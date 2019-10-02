public class solution{

     public static void main(String []args){
        int n = 100;
        long sum1 = 0,sum2 = 0 ,diff;

        for(int i = 1 ; i <= n ;i++ ){
            sum1 = sum1 + (i*i);
        }
        for(int i = 1 ; i <= n ;i++ ){
            sum2 = sum2 + i;
        }
        sum2 = sum2*sum2;
        diff = sum2 - sum1;
        System.out.println(diff);
     }
}
