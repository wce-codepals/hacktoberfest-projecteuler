#include <iostream>
#include <set>

int main()
{
  // highest number (1000000 in original problem)
  unsigned int n;
  std::cin >> n;

  // precomputation: find all prime numbers up to n
  std::set<unsigned int> primes;
  primes.insert(2);
  for (unsigned int i = 3; i <= n; i += 2)
  {
    bool isPrime = true;

    // test against all prime numbers we have so far (in ascending order)
    for (auto x : primes)
    {
      // divisible => not prime
      if (i % x == 0)
      {
        isPrime = false;
        break;
      }

      // prime is too large to be a divisor
      if (x*x > i)
        break;
    }

    // yes, we have a prime
    if (isPrime)
      primes.insert(i);
  }

  // now look at all primes
  unsigned int sum = 0;
  for (auto x : primes)
  {
    // move the right-most digit to the front of the number
    // we need to know the "position" of the front-most digit:
    // shift will be   1 for x =   1..9
    // shift will be  10 for x =  10..99
    // shift will be 100 for x = 100..999 and so on
    unsigned int shift = 1;
    while (x > shift * 10)
      shift *= 10;

    auto rotated = x;
    do
    {
      // take right-most digit
      auto digit = rotated % 10;
      // remove it
      rotated /= 10;
      // and prepend it
      rotated += digit * shift;

      // rotated number not prime ?
      if (primes.count(rotated) == 0)
        break;
    } while (rotated != x); // finished the circle ? (we have the initial number again)

    // all rotations succeeded ?
#define ORIGINAL
#ifdef ORIGINAL
    if (rotated == x)
      sum++;
#else
    if (rotated == x)
      sum += x;
#endif
  }

  std::cout << sum << std::endl;
  return 0;
}
