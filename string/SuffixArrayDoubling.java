class SuffixArray {
    private static int N = 400010;
    private static int M = 20;

    private int[] wx, wy, wss, wv;
    public int[] str, sa, rank, height;
    private int[][] mx;
    private int[] idx, p;

    public SuffixArray() {
        this.wx = new int[N];
        this.wy = new int[N];
        this.wss = new int[N];
        this.wv = new int[N];
        this.str = new int[N];
        this.sa = new int[N];
        this.rank = new int[N];
        this.height = new int[N];
        this.mx = new int[M][N];
        this.idx = new int[N];
        this.p = new int[M];
    }

    private boolean cmp(int[] r, int n, int a, int b, int l) {
        return a + l < n && b + l < n && r[a] == r[b] && r[a + l] == r[b + l];
    }

    private void da(int[] s, int[] sa, int[] rank, int[] height, int n, int m) {
        int[] x = wx, y = wy;
        int p, i, j, k;
        for (i = 0; i < m; i++)
            wss[i] = 0;
        for (i = 0; i < n; i++)
            wss[x[i] = s[i]]++;
        for (i = 1; i < m; i++)
            wss[i] += wss[i - 1];
        for (i = n - 1; i >= 0; i--)
            sa[--wss[x[i]]] = i;
        for (j = 1, p = 1; p < n && j < n; j *= 2, m = p) {
            for (i = n - j, p = 0; i < n; i++)
                y[p++] = i;
            for (i = 0; i < n; i++)
                if (sa[i] - j >= 0)
                    y[p++] = sa[i] - j;
            for (i = 0; i < n; i++)
                wv[i] = x[y[i]];
            for (i = 0; i < m; i++)
                wss[i] = 0;
            for (i = 0; i < n; i++)
                wss[wv[i]]++;
            for (i = 1; i < m; i++)
                wss[i] += wss[i - 1];
            for (i = n - 1; i >= 0; i--)
                sa[--wss[wv[i]]] = y[i];
            int[] tmp = x;
            x = y;
            y = tmp;
            for (p = 1, i = 1, x[sa[0]] = 0; i < n; i++)
                x[sa[i]] = cmp(y, n, sa[i - 1], sa[i], j) ? p - 1 : p++;
        }
        for (i = 0; i < n; i++)
            rank[sa[i]] = i;
        for (i = j = k = 0; i < n; height[rank[i++]] = k)
            if (rank[i] > 0) {
                if (k > 0) {
                    --k;
                }
                for (j = sa[rank[i] - 1]; i + k < n && j + k < n && s[i + k] == s[j + k]; k++)
                    ;
            }
        height[0] = 0;
    }

    public void init(String s) {
        int len = s.length();
        for (int i = 0; i < len; i++)
            str[i] = s.charAt(i) - 'a';
        da(str, sa, rank, height, len, 26);
    }

    public void makermq(int val[], int n) {
        idx[0] = -1;
        for (int i = 1; i < N; i++)
            idx[i] = idx[i - 1] + (((i & (i - 1)) == 0) ? 1 : 0);
        for (int i = 0; i < M; i++)
            p[i] = (1 << i);
        for (int i = 1; i <= n; i++)
            mx[0][i] = val[i];
        for (int i = 1; p[i] <= n; i++)
            for (int j = 1; j + p[i] - 1 <= n; j++)
                mx[i][j] = Math.min(mx[i - 1][j], mx[i - 1][j + p[i - 1]]);
    }

    public int lcp(int x, int y) {
        x = rank[x];
        y = rank[y];
        if (x > y) {
            int tmp = x;
            x = y;
            y = tmp;
        }
        if (x == y)
            return x - sa[x];
        x++;
        int k = idx[y - x + 1];
        return Math.min(mx[k][x], mx[k][y - p[k] + 1]);
    }
}
