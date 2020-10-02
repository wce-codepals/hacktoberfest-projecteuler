public class euler12 {
	static int gettrianglenumber(int x) {
		int sum = 0;
		for(int j = 0; j <= x; j++) {
			sum += j;
		}
		return sum;
	}
	static int getdivisorsnumber(int x) {
		int divisorsnumbervar = 0;
		for (int i = 1; i <= x; i++) {
			if(x % i == 0) {
				divisorsnumbervar += 1;
			}
		}
		return divisorsnumbervar;
	}
	public static void main(String[] args) {
		boolean numberfound = false;
		int over = 500;
		for(int i = 1; !numberfound; i++) {
			System.out.println(i);
			if(getdivisorsnumber(gettrianglenumber(i)) > over) {
				numberfound = true;
				System.out.println("bingo! the number is: " + gettrianglenumber(i));
			}
		}
	}
}
