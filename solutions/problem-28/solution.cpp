#include <iostream>

// return (base^exponent) % modulo
unsigned int powmod(unsigned long long base, unsigned int exponent, unsigned int modulo)
{
  unsigned long long result = 1;
  while (exponent > 0)
  {
    // https://en.wikipedia.org/wiki/Exponentiation_by_squaring
    // odd exponent ?
    if (exponent % 2 == 1)
    {
      result = (result * base) % modulo;
      exponent--;
    }
    else
    {
      base = (base * base) % modulo;
      exponent /= 2;
    }
  }
  return result;
}

// return modulo multiplicative inverse of a such that (a*inverse(a)) % p = 1
unsigned int inverseModulo(unsigned int a, unsigned int modulo)
{
  // if p is prime, then https://en.wikipedia.org/wiki/Fermat%27s_little_theorem applies:
  //      a^(p-1)  % p = 1
  // (a * a^(p-2)) % p = 1
  // that means a^(p-2) is the result
  return powmod(a, modulo - 2, modulo);
  // inspired by https://barkingbogart.wordpress.com/2013/02/21/cnk-mod-1000000007/
}

int main()
{
  unsigned int tests;
  std::cin >> tests;
  while (tests--)
  {
    unsigned long long n;
    std::cin >> n;

    // sum along the diagonals, initially for width = 1
    unsigned long long sum = 1;

    // brute-force approach (good enough for original problem):
    //for (int64_t width = 3; width <= n; width += 2)
    //{
      // all four corners
      //sum     += width * width;                   // upper-right
      //sum     += width * width -     (width - 1); // upper-left
      //sum     += width * width - 2 * (width - 1); // lower-left
      //sum     += width * width - 3 * (width - 1); // lower-right

      // same as:
    //  sum += 4*width*width - 6*width + 6;
    //}

    // direct computation:
    // half side length
    unsigned long long x = n / 2;
    // the closed form is:
    //sum  = 8 * x * (x + 1) * (2*x + 1) / 3   +   2 * x * (x + 1) + 4 * x + 1;

    // apply Modulo whenever an overflow is possible
    const unsigned int Modulo = 1000000007;

    x %= Modulo;

    // first part: 8 * x * (x + 1) * (2*x + 1) / 3
    //           = 4 *  sharedTerm * (2*x + 1) / 3
    unsigned long long sharedTerm = (2*x * (x + 1)) % Modulo;

    // the division by 3 becomes a multiplication by its modulo multiplicative inverse
    unsigned long long sum1 = ((4 * sharedTerm * (2*x + 1)) % Modulo) * inverseModulo(3, Modulo);

    // second part: 2 * x * (x + 1)      + 4 * x + 1
    //            =     secondTerm       + 4 * x + 1
    unsigned long long sum2 = sharedTerm + 4*x + 1;

    // sum = first part + second part
    sum = (sum1 % Modulo + sum2 % Modulo) % Modulo;

    std::cout << sum << std::endl;
  }
  return 0;
}
