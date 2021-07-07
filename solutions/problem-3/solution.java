//Add Java solution to problem-3
public class largest_prime_factor {

	public static int largest_prime_factor(long number) {
        int i;

        for (i = 2; i <= number; i++) {
            if (number % i == 0) {
                number /= i;
                i--;
            }
        }

        return i;
    }
}
