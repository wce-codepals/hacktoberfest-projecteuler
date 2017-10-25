using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace euler1 {
    class Problem5 {
        public static void Main(string[] args) {
            new Problem5().BruteForce();
            new Problem5().BruteForce1();
            new Problem5().PrimeFactoring();
        }

        public void BruteForce() {

            DateTime startTime = DateTime.Now;

            int i = 1;

            while (i %  2 != 0 || i %  3 != 0 || i %  4 != 0 || i %  5 != 0 ||
                   i %  6 != 0 || i %  7 != 0 || i %  8 != 0 || i %  9 != 0 ||
                   i % 10 != 0 || i % 11 != 0 || i % 12 != 0 || i % 13 != 0 ||
                   i % 14 != 0 || i % 15 != 0 || i % 16 != 0 || i % 17 != 0 ||
                   i % 18 != 0 || i % 19 != 0 || i % 20 != 0 ){
                      i++;
            }


            DateTime stopTime = DateTime.Now;
            TimeSpan duration = stopTime - startTime;
            Console.WriteLine("");
            Console.WriteLine("The smallest number dividable with all number 1-20 is {0}", i);
            Console.WriteLine("Solution took {0} ms", duration.TotalMilliseconds);            
        }

        public void BruteForce1() {

            DateTime startTime = DateTime.Now;

            int i = 20;

            while (i % 2 != 0 || i % 3 != 0 || i % 4 != 0 || i % 5 != 0 ||
                   i % 6 != 0 || i % 7 != 0 || i % 8 != 0 || i % 9 != 0 ||
                   i % 10 != 0 || i % 11 != 0 || i % 12 != 0 || i % 13 != 0 ||
                   i % 14 != 0 || i % 15 != 0 || i % 16 != 0 || i % 17 != 0 ||
                   i % 18 != 0 || i % 19 != 0 || i % 20 != 0) {
                i += 20;
            }


            DateTime stopTime = DateTime.Now;
            TimeSpan duration = stopTime - startTime;
            Console.WriteLine("");
            Console.WriteLine("The smallest number dividable with all number 1-20 is {0}", i);
            Console.WriteLine("Solution took {0} ms", duration.TotalMilliseconds);
        }


        public void PrimeFactoring() {
            DateTime startTime = DateTime.Now;

            int divisorMax = 20;
            int[] p = generatePrimes(divisorMax);            
            int result = 1;

            for (int i = 0; i < p.Length; i++) {              
                int a = (int) Math.Floor(Math.Log(divisorMax) / Math.Log(p[i]));                
                result = result * ((int)Math.Pow(p[i],a));
            }
          
            DateTime stopTime = DateTime.Now;
            TimeSpan duration = stopTime - startTime;
            Console.WriteLine("");
            Console.WriteLine("The smallest number dividable with all number 1-20 is {0}", result);
            Console.WriteLine("Solution took {0} ms", duration.TotalMilliseconds);  
        }


        private int[] generatePrimes(int upperLimit){
            List<int> primes = new List<int>();
            bool isPrime;
            int j;

            primes.Add(2);

            for (int i = 3; i <= upperLimit; i += 2) {                
                j = 0;
                isPrime = true;
                while (primes[j]*primes[j] <= i) {
                    if (i % primes[j] == 0) {
                        isPrime = false;
                        break;
                    }
                    j++;
                }
                if (isPrime) {
                    primes.Add(i);
                }
            }

            return primes.ToArray<int>();            
        }            
    }
}
