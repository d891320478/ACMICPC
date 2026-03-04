public class Rmq {

    private static final int M = 20;

    private int[][] mx, mn;
    private int[] p, idx;

    public Rmq(int n) {
        mx = new int[M][n];
        mn = new int[M][n];
        p = new int[20];
        idx = new int[M];
        idx[0] = -1;
        for (int i = 1; i < n; i++) {
            idx[i] = idx[i - 1] + ((i & (i - 1)) == 0 ? 1 : 0);
        }
        for (int i = 0; i < M; i++) {
            p[i] = 1 << i;
        }
    }

    public void init(int[] a) {
        int n = a.length;
        for (int i = 0; i < n; i++) {
            mx[0][i] = mn[0][i] = a[i];
        }
        for (int i = 1; p[i] <= n; i++) {
            for (int j = 0; j + p[i] - 1 < n; j++) {
                mx[i][j] = Math.max(mx[i - 1][j], mx[i - 1][j + p[i - 1]]);
                mn[i][j] = Math.min(mn[i - 1][j], mn[i - 1][j + p[i - 1]]);
            }
        }
    }

    public int max(int l, int r) {
        int t = idx[r - l + 1];
        return Math.max(mx[t][l], mx[t][r - p[t] + 1]);
    }

    public int min(int l, int r) {
        int t = idx[r - l + 1];
        return Math.min(mn[t][l], mn[t][r - p[t] + 1]);
    }
}
