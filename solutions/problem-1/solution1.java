/**
 * 
 * @author Harry
 *
 */
public class solution1 {

	public static void main(String[] args) {
		// prints out the sum of all multiples of 3 and 5 less than 1000
		int[] multipleCheck = {3,5};
		int total = 1000;
		int sum = 0;
		for (int i = 0; i < total; i++) {
			int number = i;
			if (i % multipleCheck[0] == 0 || i % multipleCheck[1] == 0) {
				sum += number;
			}
		}
		System.out.println(sum);
	}

}
