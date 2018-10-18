import java.util.Scanner;
class practice2
{
   public static void main(String args[])
   {
    Scanner input=new Scanner(System.in);
   int n=input.nextInt();
   int fact=1;
   int sum=0;
   
   while(n > 0)
   {
    int p=n % 10;
    for(int i=1;i<=p;i++)
    {
      fact=fact*i;
      
    }
    sum=sum+fact;
    System.out.println(sum);
    fact=1;
     
    n=n/10;

   }

  

    }
  
}
