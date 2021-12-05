#include <iostream>

// return true if x is prime
bool isPrime(int x)
{
  // reject invalid input
  if (x <= 1)
    return false;

  // process all potential divisors
  for (int factor = 2; factor*factor <= x; factor++)
    if (x % factor == 0)
      return false;

  // no such divisor found, it's a prime number
  return true;
}

int main()
{
  // upper and lower limit of the coefficients
  int limit;
  std::cin >> limit;
  // make sure it's a positive number
  if (limit < 0)
    limit = -limit;

  // keep track of best sequence:
  // number of generated primes
  unsigned int consecutive = 0;
  // its coefficients
  int bestA = 0;
  int bestB = 0;

  // simple brute-force approach
  for (int a = -limit; a <= +limit; a++)
    for (int b = -limit; b <= +limit; b++)
    {
      // count number of consecutive prime numbers
      unsigned int length = 0;
      while (isPrime(length * length + a * length + b))
        length++;

      // better than before ?
      if (consecutive < length)
      {
        consecutive = length;
        bestA = a;
        bestB = b;
      }
    }

#define ORIGINAL
#ifdef ORIGINAL
  // print a*b
  std::cout << (bestA * bestB) << std::endl;
#else
  // print best factors
  std::cout << bestA << " " << bestB << std::endl;
#endif
  return 0;
}
