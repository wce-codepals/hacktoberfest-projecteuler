public class problem6 {
	public static void main(String[] args) {
		int n = 100;

		long sum_of_squares = (n * (n + 1) * (2 * n + 1) ) / 6;
		long square_sum = (long) Math.pow( (n *(n + 1) / 2) , 2);

		long ans = square_sum - sum_of_squares;
		System.out.println(ans);
	}
}