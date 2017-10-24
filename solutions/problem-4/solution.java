// Author: Glen Johnson (@gj-codes)
// Date: 10-24-2017

public class Main {
    
    public static void main(String[] args) {
        System.out.println("Here's the highest palindrome: " + calculate());
    }
    
    
    public static int calculate() {
        int max = 0;
        // only checking product of 3 digit numbers
        for (int i = 100; i < 1000; i++) {
            for (int j = 100; j < 1000; j++) {
                int prod = i * j;
                if (isPalindrome(prod) && (prod > max))
                    max = prod;
            }
        }
        return max;
    }
    
    public static boolean isPalindrome(int num) {
        String val = Integer.toString(num);
        String rev = new StringBuffer(val).reverse().toString();
        if (val.equals(rev))
            return true;
        else
            return false;
    }
}
