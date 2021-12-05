#include <iostream>
#include <vector>

int main()
{
  // compute the first 10001 primes
  std::vector<unsigned int> primes;
  primes.reserve(10001);
  primes.push_back(2);
  for (unsigned int x = 3; primes.size() <= 10000; x += 2)
  {
    bool isPrime = true;
    for (auto p : primes)
    {
      // found a divisor ? => abort
      if (x % p == 0)
      {
        isPrime = false;
        break;
      }

      // no larger prime factors possible ?
      if (p*p > x)
        break;
    }

    // yes, we have a new prime
    if (isPrime)
      primes.push_back(x);
  }

  unsigned int x; //enter 10001
  std::cin >> x;
  x--;

  if (x < primes.size())
    std::cout << primes[x] << std::endl;
    
  return 0;
}
