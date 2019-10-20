using System;

namespace FirstApplication
{
    public class Program
    {

        public static bool IsPrime(int n)
        {
            if (n < 2) return false;
            else if (n == 2) return true;
            for (int i = 2; i <= n/2; i++)
            {
                if (n % i == 0)
                {
                    return false;
                }
            }
            return true;
        }

        public static void Main(string[] args)
        {
            int count = 1, x = 2;
            while (count < 10001)
            {
                x++;
                if (IsPrime(x))
                {
                    count++;
                }
            }
            Console.WriteLine(x);

        }
    }
}
