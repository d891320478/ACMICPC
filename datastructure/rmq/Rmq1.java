public class Rmq {

    private static final int M = 25;

    private int[][] or;
    private int[] p, idx;

    public Rmq(int n) {
        or = new int[M][n];
        p = new int[M];
        idx = new int[n + 1];
        idx[0] = -1;
        for (int i = 1; i <= n; i++) {
            idx[i] = idx[i - 1] + ((i & (i - 1)) == 0 ? 1 : 0);
        }
        for (int i = 0; i < M; i++) {
            p[i] = 1 << i;
        }
    }

    public void init(int[] a) {
        int n = a.length;
        for (int i = 0; i < n; i++) {
            or[0][i] = a[i];
        }
        for (int i = 1; p[i] <= n; i++) {
            for (int j = 0; j + p[i] - 1 < n; j++) {
                or[i][j] = or[i - 1][j] | or[i - 1][j + p[i - 1]];
            }
        }
    }

    public int or(int l, int r) {
        int t = idx[r - l + 1];
        return or[t][l] | or[t][r - p[t] + 1];
    }
}
