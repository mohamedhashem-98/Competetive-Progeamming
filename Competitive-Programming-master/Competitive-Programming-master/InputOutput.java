static class Scanner {
		BufferedReader br;
		StringTokenizer st;
 
		Scanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}
 
		Scanner(String fileName) throws FileNotFoundException {
			br = new BufferedReader(new FileReader(fileName));
		}
 
		String next() throws IOException {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}
 
		String nextLine() throws IOException {
			return br.readLine();
		}
 
		int nextInt() throws IOException {
			return Integer.parseInt(next());
		}
 
		long nextLong() throws NumberFormatException, IOException {
			return Long.parseLong(next());
		}
 
		double nextDouble() throws NumberFormatException, IOException {
			return Double.parseDouble(next());
		}
 
		boolean ready() throws IOException {
			return br.ready();
		}
 
	}