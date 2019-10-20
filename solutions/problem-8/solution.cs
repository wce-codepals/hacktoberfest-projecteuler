using System;

namespace FirstApplication
{
    public class Program
    {
        public static void Main(string[] args)
        {
            string line, x = "";
            int pos = 0;
            long sum = 0, max = 0;

            // Taking the input as seperate lines as per website
            while ((line = Console.ReadLine()) != "-1")
            {
                x += line;
            }

            while (pos + 13 <= x.Length)
            {
                string slot = x.Substring(pos, 13);
                char[] slotarr = slot.ToCharArray();
                int[] elements = Array.ConvertAll(slotarr, c => (int)Char.GetNumericValue(c));

                sum = CalculateSum(elements);

                if (sum > max)
                {
                    max = sum;
                }
                pos++;
            }
            Console.WriteLine(max);
        }

        private static long CalculateSum(int[] elements)
        {
            long res = 1;
            foreach(int i in elements)
            {
                res = res * i;
            }
            return res;
        }
    }
}
