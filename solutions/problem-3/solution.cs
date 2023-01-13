using System; 
  
class  { 
  
    
    static long maxPrimeFactors(long n) 
    { 
        
        long maxPrime = -1; 
        while (n % 2 == 0) { 
            maxPrime = 2; 

            n >>= 1; 
        } 
        for (int i = 3; i <= Math.Sqrt(n); i += 2) { 
            while (n % i == 0) { 
                maxPrime = i; 
                n = n / i; 
            } 
        } 
  
        if (n > 2) 
            maxPrime = n; 
  
        return maxPrime; 
    } 
   
    public static void Main() 
    {   int t = Convert.ToInt32(Console.ReadLine());
        for(int i=0;i<t;i++)
        {   
            int n1 = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine(maxPrimeFactors(n1));  
        }
         
    } 
} 
