import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {

    static Scanner in = new Scanner(System.in);

    public static void main(String[] args) {
        int _t = in.nextInt();
        long[][] dp = new long[20][170];
        boolean[][] vis = new boolean[20][170];
        while (_t-- > 0) {
            long l = in.nextLong();
            long r = in.nextLong();
            System.out.println(((f(r, dp, vis) - f(l - 1, dp, vis)) % MOD + MOD) % MOD);
        }
    }

    private static long f(long x, long[][] dp, boolean[][] vis) {
        if (x == 0) {
            return 0;
        }
        int la = 0;
        int[] a = new int[20];
        while (x > 0) {
            a[++la] = (int)(x % 10);
            x /= 10;
        }
        return dfs(a, la, true, 0, dp, vis);
    }

    private static long dfs(int[] a, int la, boolean limit, int pre, long[][] dp, boolean[][] vis) {
        if (la == 0) {
            return pre;
        }
        if (!limit && vis[la][pre]) {
            return dp[la][pre];
        }
        long sum = 0;
        for (int i = 0; i <= (limit ? a[la] : 9); ++i) {
            sum = sum + dfs(a, la - 1, limit && i == a[la], pre + i, dp, vis);
            sum %= MOD;
        }
        if (!limit) {
            vis[la][pre] = true;
            dp[la][pre] = sum;
        }
        return sum;
    }
}
