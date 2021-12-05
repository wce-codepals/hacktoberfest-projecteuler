public class test {

	public static void main(String[] args) {
		int num = 1;
		int total = 0;
		while (num < 1000) {
			if (num % 3 == 0 || num % 5 == 0) {
				total += num;
			}
			num++;
		}
		System.out.println(total);
	}

}
