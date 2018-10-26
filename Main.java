class Main {
  public static void main(String[] args) {
   
    long i,a=2520,b=0;
    do{
      for (i=1;i<=20;i++)
      {
        if (a%i==0)
        b=b+1;
      }
      a++;
      if (b==20)
      break;
    }while(true);
     System.out.print("The smallest number which is divisible by all numbers from 1 to 20:"+a);
    }

   
  }
