

#include <iostream>
#include <vector>

// return (a*b) % modulo
unsigned long long mulmod(unsigned long long a, unsigned long long b, unsigned long long modulo)
{
  // fast path
  if (a <= 0xFFFFFFF && b <= 0xFFFFFFF)
    return (a * b) % modulo;

  // we might encounter overflows (slow path)
  unsigned long long result = 0;
  unsigned long long factor = a % modulo;

  // bitwise multiplication
  while (b > 0)
  {
    // b is odd ? a*b = a + a*(b-1)
    if (b & 1)
    {
      result += factor;
      if (result >= modulo)
        result %= modulo;
    }

    // b is even ? a*b = (2*a)*(b/2)
    factor <<= 1;
    if (factor >= modulo)
      factor %= modulo;

    // next bit
    b >>= 1;
  }

  return result;
}

// return (base^exponent) % modulo
unsigned long long powmod(unsigned long long base, unsigned long long exponent, unsigned long long modulo)
{
  unsigned long long result = 1;
  while (exponent > 0)
  {
    // fast exponentation:
    // odd exponent ? a^b = a*a^(b-1)
    if (exponent & 1)
      result = mulmod(result, base, modulo);

    // even exponent ? a^b = (a*a)^(b/2)
    base = mulmod(base, base, modulo);
    exponent >>= 1;
  }
  return result;
}

// Miller-Rabin-test
bool isPrime(unsigned long long p)
{
  // some code from             https://ronzii.wordpress.com/2012/03/04/miller-rabin-primality-test/
  // with optimizations from    http://ceur-ws.org/Vol-1326/020-Forisek.pdf
  // good bases can be found at http://miller-rabin.appspot.com/

  // trivial cases
  const unsigned int bitmaskPrimes2to31 = (1 <<  2) | (1 <<  3) | (1 <<  5) | (1 <<  7) |
                                          (1 << 11) | (1 << 13) | (1 << 17) | (1 << 19) |
                                          (1 << 23) | (1 << 29); // = 0x208A28Ac
  if (p < 31)
    return (bitmaskPrimes2to31 & (1 << p)) != 0;

  if (p %  2 == 0 || p %  3 == 0 || p %  5 == 0 || p % 7 == 0 || // divisible by a small prime
      p % 11 == 0 || p % 13 == 0 || p % 17 == 0)
    return false;

  if (p < 17*19) // we filtered all composite numbers < 17*19, all others below 17*19 must be prime
    return true;

  // test p against those numbers ("witnesses")
  // good bases can be found at http://miller-rabin.appspot.com/
  const unsigned int STOP = 0;
  const unsigned int TestAgainst1[] = { 377687, STOP };
  const unsigned int TestAgainst2[] = { 31, 73, STOP };
  const unsigned int TestAgainst3[] = { 2, 7, 61, STOP };
  // first three sequences are good up to 2^32
  const unsigned int TestAgainst4[] = { 2, 13, 23, 1662803, STOP };
  const unsigned int TestAgainst7[] = { 2, 325, 9375, 28178, 450775, 9780504, 1795265022, STOP };

  // good up to 2^64
  const unsigned int* testAgainst = TestAgainst7;
  // use less tests if feasible
  if (p < 5329)
    testAgainst = TestAgainst1;
  else if (p < 9080191)
    testAgainst = TestAgainst2;
  else if (p < 4759123141ULL)
    testAgainst = TestAgainst3;
  else if (p < 1122004669633ULL)
    testAgainst = TestAgainst4;

  // find p - 1 = d * 2^j
  auto d = p - 1;
  d >>= 1;
  unsigned int shift = 0;
  while ((d & 1) == 0)
  {
    shift++;
    d >>= 1;
  }

  // test p against all bases
  do
  {
    auto x = powmod(*testAgainst++, d, p);
    // is test^d % p == 1 or -1 ?
    if (x == 1 || x == p - 1)
      continue;

    // now either prime or a strong pseudo-prime
    // check test^(d*2^r) for 0 <= r < shift
    bool maybePrime = false;
    for (unsigned int r = 0; r < shift; r++)
    {
      // x = x^2 % p
      // (initial x was test^d)
      x = powmod(x, 2, p);
      // x % p == 1 => not prime
      if (x == 1)
        return false;

      // x % p == -1 => prime or an even stronger pseudo-prime
      if (x == p - 1)
      {
        // next iteration
        maybePrime = true;
        break;
      }
    }

    // not prime
    if (!maybePrime)
      return false;
  } while (*testAgainst != STOP);

  // prime
  return true;
}

std::vector<unsigned int>       primes;
std::vector<unsigned long long> primeSum;

// make sure that at least "num" primes are available in "primes"
void morePrimes(unsigned int num)
{
  if (primes.empty())
  {
    primes  .reserve(400000);
    primeSum.reserve(400000);

    primes.push_back(2);
    primes.push_back(3);

    primeSum.push_back(2);
  }

  for (auto i = primes.back() + 2; primes.size() <= num; i += 2)
  {
    bool isPrime = true;
    // test against all prime numbers we have so far (in ascending order)
    for (auto x : primes)
    {
      // prime is too large to be a divisor
      if (x*x > i)
        break;

      // divisible => not prime
      if (i % x == 0)
      {
        isPrime = false;
        break;
      }
    }

    // yes, we have a prime
    if (isPrime)
      primes.push_back(i);
  }

  for (auto i = primeSum.size(); i < primes.size(); i++)
    primeSum.push_back(primeSum.back() + primes[i]);
}

int main()
{
  // generate some primes
  const unsigned int PrimesPerBatch = 10000;
  morePrimes(PrimesPerBatch);

  unsigned int tests;
  std::cin >> tests;
  while (tests--)
  {
    unsigned long long last = 1000000;
    std::cin >> last;

    unsigned long long best = 2; // highest prime sum
    unsigned int maxLength  = 0; // longest chain (must add plus one)

    // all sequences start with surprisingly small prime numbers
    // a brute-force search showed that all "good" chains start at 2..131
    unsigned int start = 0; // primes[0] = 2
    while (primes[start] <= 131 && primes[start] <= last)
    {
      unsigned long long subtract = 0;
      if (start > 0)
        subtract = primeSum[start - 1];

      unsigned int pos = start + maxLength;
      // find shortest chain whose sum exceeds the limit
      while (primeSum[pos] - subtract <= last)
      {
        pos++;
        // running out of prime numbers ? add more !
        if (pos + 100 >= primes.size()) // plus 100 is probably too cautious
          morePrimes(primes.size() + PrimesPerBatch);
      }
      pos--;

      // chop off one prime number until the sum is prime, too
      while (pos - start > maxLength)
      {
        unsigned long long sum = primeSum[pos] - subtract;
        // yes, we have a good candidate (maybe better ones for other values of "start", though)
        if (isPrime(sum))
        {
          maxLength = pos - start;
          best = sum;
          break;
        }

        pos--;
      }

      start++;
    }

    // if sum is > 0 then "length" didn't count the first element
    if (best >= 2)
      maxLength++;
    std::cout << best << " " << maxLength << std::endl;
  }

  return 0;
}
