public class ProjectEuler {

    public static void main(String[] args) {
    
        System.out.println(solveP2());
    }
    
   
    public static long solveP2()
    {
    
      long x = 1;
      long y = 2;
      long temp = 0;
      long sum = 0;
      for(long i = 1; y <= 4000000; i++)
      {
          temp = x;
          if(y%2 == 0)
          {
              sum += y;
          }
          x = y;
          y = y + temp;
      }
      return sum;
    }
    
    
    
}
