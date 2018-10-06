using System;

namespace Euler
{

    class Program
    {
        const int MAX = 1000;

        static void Main(string[] args)
        {
            int sum = 0;

            for (int x=0; x<MAX; x++)
            {
                if ((x % 3 == 0) || (x % 5 == 0))
                {
                    sum += x;
                }
            }

            Console.WriteLine("Sum: " + sum) ;
        }
    }
}
