public class Palindromic {

	public static void main(String[] args) {
		int firstNum = 0;
		int secondNum = 0;
		int solution = 0;
		for (secondNum = 100; secondNum < 1000; secondNum++) {
			for (firstNum = 100; firstNum < 1000; firstNum++) {
				boolean isPalindrome = true;
				String s = Integer.toString(firstNum * secondNum);
				while (s.length() > 1 && isPalindrome) {
					if (s.charAt(0) == s.charAt(s.length()-1)) {
						System.out.println("FirstNum: " + firstNum + " SecondNum: " + secondNum + " S: " + s);
						s = s.substring(1, s.length()-1);
					} else {
						isPalindrome = false;
					}
				}
				if (firstNum * secondNum > solution && isPalindrome) {
					solution = firstNum * secondNum;
				}
			}
		}
		System.out.println(solution);
	}

}
