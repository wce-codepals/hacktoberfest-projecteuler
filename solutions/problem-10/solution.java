/*
 The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 Find the sum of all the primes below two million.
*/

public class solution {

    public static void main(String[] args) {

        long maxNo = 2000000;
        long totalPrimeSum = 0;

        for(int i=0;i<=maxNo;i++){

            if(isPrime(i))
                totalPrimeSum += i;
        }

        System.out.println("Sum of all prime number below two-million is: "+totalPrimeSum);
    }

    
    static boolean isPrime(int no) {

        /*
            Function returns True if number is prime otherwise returns False.
            To get efficient output in very less time, for a really big data(like 2 million),
            here I have used AKS algorithm.
            You can use other efficient primality-proving algorithm to implement this.
    
            Resources:
            1) https://en.wikipedia.org/wiki/AKS_primality_test
            2) https://www.quora.com/Is-every-prime-number-other-than-2-and-3-of-the-form-6k%C2%B11-Is-this-a-proven-result-What-are-other-resources-about-it
        */

        if (no == 2)
            return true;
        if (no == 3)
            return true;
        if (no % 2 == 0)
            return false;
        if (no % 3 == 0)
            return false;

        int tempVariable1 = 5;
        int tempVariable2 = 2;

        while (tempVariable1 * tempVariable1 <= no) {
            if (no % tempVariable1 == 0)
                return false;

            tempVariable1 += tempVariable2;
            tempVariable2 = 6 - tempVariable2;
        }

        return true;
    }

}