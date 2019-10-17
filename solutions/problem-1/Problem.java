import java.util.Scanner;
public class Problem1 {
    //multiples of 3 or 5

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t =sc.nextInt();    //taking input Number of test cases        
        int sum;
        for(int a0 = 0; a0 < t; a0++){
            int n = sc.nextInt(); //limiting N number
            sum=0;
            for(int i=1;i<n;i++)
            {
                if(i%3==0||i%5==0)
                {
                    sum=sum+i;
                }
            }
            System.out.println(sum);
        }
        sc.close();
    }
}
