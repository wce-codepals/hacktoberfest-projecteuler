import java.math.BigInteger;

public class ProjectEuler13Solution {
  public static void main(String[] args) {
    int i = 0;
    int cnt = 2;
    BigInteger limit = (new BigInteger("10")).pow(999);
    BigInteger[] fib = new BigInteger[3];

    fib[0] = BigInteger.ONE;
    fib[2] = BigInteger.ONE;

    while ((fib[i]).compareTo(limit) < 0) {
        i = (i + 1) % 3;
        cnt++;
        fib[i] = fib[(i + 1) % 3].add(fib[(i + 2) % 3]);
    }
    System.out.printf("Fibonacci %d has 1000 digits\n", cnt);
  }
}
