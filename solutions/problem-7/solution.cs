using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace euler1 {
    class Problem7 {

        public static void Main(string[] args) {
            new Problem7().BruteForce();
            new Problem7().Smart();
        }

        public void BruteForce() {
            DateTime startTime = DateTime.Now;
            
            int numPrimes = 1;
            int numm = 1;

            while (numPrimes < 10001) {
                numm = numm + 2;

                if (isPrime(numm)) {
                    numPrimes++;
                }
            }

            DateTime stopTime = DateTime.Now;
            TimeSpan duration = stopTime - startTime;
            Console.WriteLine("Prime number {0} is {1} ", numPrimes, numm);
            Console.WriteLine("Solution took {0} ms", duration.TotalMilliseconds);
        }

        private bool isPrime(int numm) {

            if (numm <= 1) {
                return false;
            }

            if (numm == 2) {
                return true;
            }

            if (numm % 2 == 0) {
                return false;
            }

            int counter = 3;     

            while ((counter * counter) <= numm) {
                if (numm % counter == 0) {
                    return false;
                } else {
                    counter +=2;
                }
            }

            return true;
        }
     
        public void Smart() {            
            DateTime startTime = DateTime.Now;
           
            int upperLimit = 10001;                        
            int counter = 1;

            bool isPrime;
            int j;
            List<int> primes = new List<int>();

            primes.Add(2);          
            
           while(primes.Count < upperLimit){
                counter += 2; 
                j = 0;
                isPrime = true;
                while (primes[j]*primes[j] <= counter) {
                    if (counter % primes[j] == 0) {
                        isPrime = false;
                        break;
                    }
                    j++;
                }
                if (isPrime) {
                    primes.Add(counter);
                }               
            }

            DateTime stopTime = DateTime.Now;
            TimeSpan duration = stopTime - startTime;
            Console.WriteLine("Prime number {0} is {1} ", upperLimit, counter);
            Console.WriteLine("Solution took {0} ms", duration.TotalMilliseconds);          
        }          
    }
}
