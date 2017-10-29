public class solution {
	public static void main(String[] args) {
		long n = 600851475143;
		long i = 2;
		while ((i * i) <= n) {
			if (n%i != 0) {
				i += 1;
			} 
			else {
				n = (long) Math.floor(n/i);
			}
		}
		System.out.println(n);
	}
}