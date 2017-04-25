class Fastget {

	public BufferedReader in;
	public StringTokenizer st;
	public static final PrintWriter out = new PrintWriter(System.out);

	public Fastget() {
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

	public Integer nextInt() {
		String s = next();
		if (s == null || s.isEmpty()) {
			return null;
		}
		return Integer.parseInt(s);
	}

	public Long nextLong() {
		String s = next();
		if (s == null || s.isEmpty()) {
			return null;
		}
		return Long.parseLong(s);
	}

	public Double nextDouble() {
		String s = next();
		if (s == null || s.isEmpty()) {
			return null;
		}
		return Double.parseDouble(s);
	}

}
