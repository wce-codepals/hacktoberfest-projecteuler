    package projecteuler ;

    public class problem20 {

        public static void main(String[] args) {
            BigInteger carpim = BigInteger.ONE;
            for (int i = 100; i >= 1; i--) {
                carpim = carpim.multiply(BigInteger.valueOf(i));
            }
            System.out.println(carpim);
        }
    }