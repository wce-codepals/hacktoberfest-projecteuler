public class Fibonacci {

	public static void main(String[] args) {
		int prevNumber = 1;
		int curNumber = 2;
		int total = 2;
		while (curNumber < 4000000) {
			int temp = prevNumber + curNumber;
			if (temp % 2 == 0) {
				total += temp;
			}
			prevNumber = curNumber;
			curNumber = temp;
		}
		System.out.println(total);
	}
	
}
