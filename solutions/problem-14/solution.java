public static void main (String[] args) {
    int max = 0;
    int num = 0;
    int result = 0;
    int chainSize = 0;

    for (int i = 2; i < 100000; i++) {
        chainSize = 0;
        num = i;
        while (num != 1) {
            if (num % 2 == 0) {
                num = num / 2;
            } else {
                num = 3 * num + 1;
            }
            chainSize++;
        }
        if (chainSize > max) {
            max = chainSize;
            result = i;
        }
    }

    System.out.printf("%d, %d", result, max);
}