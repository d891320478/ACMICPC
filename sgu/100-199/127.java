import java.util.*;
import java.io.*;

public class Solution {

	public static void main(String[] args) throws IOException {

		fastget in = new fastget();
		PrintWriter out = new PrintWriter(System.out);
		int k = in.nextInt();
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; ++i)
			a[i] = in.nextInt();
		Arrays.sort(a);
		int ans = 1;
		for (int i = 1, j = 1; i < n; ++i) {
			if (j == k) {
				j = 1;
				++ans;
			} else {
				if (a[i] / 1000 == a[i - 1] / 1000)
					++j;
				else {
					++ans;
					j = 1;
				}
			}
		}
		out.printf("%d\n", ans + 2);
		out.close();

	}
}

class fastget {

	public BufferedReader in;
	public StringTokenizer st;

	public fastget() {
		in = new BufferedReader(new InputStreamReader(System.in));
	}

	private String next() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(in.readLine());
			} catch (Exception e) {
			}
		}
		return st.nextToken();
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}

	public long nextLong() {
		return Long.parseLong(next());
	}

	public double nextDouble() {
		return Double.parseDouble(next());
	}

}