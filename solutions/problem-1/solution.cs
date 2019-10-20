using System;
using System.Collections.Generic;
using System.Linq;

namespace FirstApplication
{
    public class Program
    {
        public static void Main(string[] args)
        {
            var elements = new List<int>();
            for(int i = 1;  i< 1000; i++)
            {
                if (i % 3 == 0 || i % 5 == 0)
                {
                    elements.Add(i);
                }
            }
            Console.WriteLine(elements.Sum());
        }

    }

}
