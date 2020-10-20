public static void main(String[] args) {
        System.out.println(orderestPrime(10001));
    }

    public static int orderestPrime(int order) {
        int value = 0;
        while (order-- > 0){
            while(!isPrime(++value));
        }
        return value;
    }

    public static boolean isPrime(int value) {
        if (value == 2) return true;
        if ((value % 2 == 0) || value <= 1) return false;

        int sqrtValue = (int) Math.sqrt(value) + 1;

        int range = 1;

        while (value % (range += 2) != 0 && range <= sqrtValue) ;

        return range > sqrtValue;
    }
}