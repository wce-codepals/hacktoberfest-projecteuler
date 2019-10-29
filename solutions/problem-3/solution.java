public class LargestPrimeFactor {

	public static void main(String[] args) {
		long num = 600851475143L;
		long currentPrimeNumber = 0;
		for (long j = 2; j < num/2; j++) {
			if (num % j == 0) {
				boolean isPrime = true;
				for (long i = 2; i < j/2; i++) {
					if (j % i == 0) {
						isPrime = false;
					}
				}
				if (isPrime) {
					currentPrimeNumber = j;
					System.out.println(j);
				}
			}
			//System.out.println(num);
		}
		System.out.println(currentPrimeNumber + "end");
	}

}
