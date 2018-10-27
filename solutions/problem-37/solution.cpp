#include <set>
#include <iostream>

int main()
{
  // find all primes up to
  unsigned int n;
  std::cin >> n; // 1000000 is sufficient for the original problem

  // will contain all primes found so far
  std::set<unsigned int> primes;
  // all single-digit prime numbers (2,3,5,7) are not truncatable by definition
  primes.insert(2);
  primes.insert(3);
  primes.insert(5);
  primes.insert(7);

  unsigned int sum = 0;
  // check prime numbers with at least two digits
  // note: even numbers cannot be prime (except 2)
  for (unsigned int i = 11; i < n; i += 2)
  {
    bool isPrime = true;
    // check against all known primes
    for (auto p : primes)
    {
      // no more prime factors possible
      if (p*p > i)
        break;

      // divisible by another prime ? => i is not prime
      if (i % p == 0)
      {
        isPrime = false;
        break;
      }
    }

    if (!isPrime)
      continue;

    // now we have a prime
    primes.insert(i);

    // check whether truncable from the right side
    auto right = i;
    // remove right-most digit if still prime and until no digits remain
    while (right > 0 && primes.count(right) != 0)
      right /= 10;
    // pass only if all digits were successfully removed
    if (right != 0)
      continue;

    // same idea from the left side
    auto left = i;
    // find position of left-most digit
    unsigned int factor = 1;
    while (factor * 10 <= left)
      factor *= 10;
    // remove left-most digit if still prime and until no digits remain
    while (left > 0 && primes.count(left) != 0)
    {
      // fast version:
      left %= factor;
      // slower version: subtract until highest digit is completely gone (=zero)
      //while (left >= factor)
      // left -= factor;

      // okay, next digit is 10 times smaller
      factor /= 10;
    }
    // pass only if all digits were successfully removed
    if (left != 0)
      continue;

    // yeah, passed all tests !
    sum += i;
  }

  std::cout << sum << std::endl;
  return 0;
}
