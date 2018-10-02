public class Solution {
	public static void main(String[] args){
		/*
		 * Problem Statement:
		 * 
		 * Find the difference between the sum of squares and
		 * the square of the sum for the first 100 natural numbers.
		 *
		 */

		// variable to determine how many numbers to take
		int n = 100;
		
		// Sum of first n natural numbers = n * (n+1)/2
		int square_of_sum = (n * (n+1))/2;
		square_of_sum *= square_of_sum;
		
		// Sum of sqaures of first n natural numbers = n*(n+1)*(2*n+1)/2
		int sum_of_squares = (n * (n + 1) * (2*n + 1))/2;
		
		System.out.println(square_of_sum - sum_of_squares);
	}
}
