class fastget {
	
	public BufferedReader in;
	public StringTokenizer st;
	
	public fastget() {
		in = new BufferedReader(new InputStreamReader(System.in));
	}
	
	private String next() {
		while (st==null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(in.readLine());
			} catch (Exception e) {}
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
