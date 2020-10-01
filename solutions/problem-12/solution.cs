namespace ProjectEuler
{
    class Program
    {
        static void Main(string[] args)
        {
            Problem12 p = new Problem12();
            Int64 i = p.GetTriangleNumberHavingMoreThan500Divisors();
            Console.WriteLine(i.ToString());
            Console.ReadKey(true);
        }
    }
 
    public class Problem12
    {
        public Int64 GetTriangleNumberHavingMoreThan500Divisors()
        {
            Int64 i;
            for (i = 500; ; i++)
            {
                Int64 k = GetATriangleNumber(i);
                bool b = CheckFor500Divisors(k);
                if (b)
                    return k;
            }
            return 0;
        }
 
        public bool CheckFor500Divisors(Int64 k)
        {
            int iCount = 0;
            Int64 l = k;
            for (Int64 i = 1; i &amp;lt;= l; i++)
            {
                if (k % i == 0)
                {
                    iCount = iCount + 2;
                }
                l = k / i;
            }
            if (iCount &amp;gt; 500)
                return true;
            else
                return false;
        }
        public Int64 GetATriangleNumber(Int64 i)
        {
            return i * (i + 1) / 2;
        }
    }
}
