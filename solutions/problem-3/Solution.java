import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();  //number of the test cases
        long temp;
        for(int a0 = 0; a0 < t; a0++){
            long n = in.nextLong(); // number for which the largest primes needs to be checked
            temp=1;
            for(int i=1;i<=n/2;i++)
            {
                if(n%i==0)
                {
                    temp=i;  // swapping the value of next prime in temp
                }
                else 
                {
                    temp=n;  // in case when the number is divisible by itself only
                }
            }
            System.out.println(temp);
        } 
        in.close();
    }
}

