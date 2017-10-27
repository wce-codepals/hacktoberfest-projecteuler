class Run
{
    public static void main(String args[])
    {
        int sum_of_squares,square_of_sum,n=10,difference;
        sum_of_squares=n*(n+1)*(2*n+1)/6;
        square_of_sum=(int)Math.pow(n*(n+1)/2,2);
        difference=sum_of_squares-square_of_sum;
        System.out.println("Difference between sum of square and square of sum is "+difference);
    }
}
