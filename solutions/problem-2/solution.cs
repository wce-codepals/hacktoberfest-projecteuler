using System;
using System.Collections.Generic;

namespace FirstApplication
{
    public class Program
    {
        public static void Main(string[] args)
        {
            var elements = new List<int> { 1, 2 };
            int a = 1, b = 2, c = 0;
            long sum = 0;

            while (c <= 4000000)
            {
                c = a + b;
                a = b;
                b = c;

                if (c <= 4000000)
                {
                    elements.Add(c);
                }
            }

            for (int i = 0; i < elements.Count; i++)
            {
                if (elements[i] % 2 == 0)
                {
                    sum += elements[i];
                }
            }

            Console.WriteLine(sum);
        }

    }

}
