
public class Primes {
    public static void main(String[] args) {
        System.out.println(sumPrimeNumbers(2000000));
    }

    public static int sumPrimeNumbers(int range) {
        int sum = 0;
        while(range-- > 0){
            sum+= isPrime(range) ? range:0;
        }
        return sum;
    }

    public static boolean isPrime(int value) {
        if (value == 2) return true;
        if ((value % 2 == 0) || value <= 1) return false;

        int sqrtValue = (int) Math.sqrt(value) + 1;

        int range = 1;

        while (value % (range += 2) != 0 && range <= sqrtValue) ;

        if(range > sqrtValue){
            return true;
        }
        return false;

    }


}