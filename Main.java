class Main {
  public static void main(String[] args) {
    int sum=0, a, b;
    for (a=3; a<1000; a=a+3)
    {
      sum=sum+a;
    }
    for (b=5; b<1000; b=b+5)
    {
      sum=sum+b;
    }
    System.out.print("the sum of all the multiples of 3 or 5 below 1000:"+sum);
  }
}