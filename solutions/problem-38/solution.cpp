#include <iostream>

int main()
{
  unsigned int maxFactor, maxDigit;  // 10000 and 9 for the original problem
  std::cin >> maxFactor >> maxDigit;

  // bitmask if all digits are used
  unsigned int bitsAll = 0;
  for (unsigned int i = 1; i <= maxDigit; i++)
    bitsAll |= 1 << i;

#define ORIGINAL
#ifdef ORIGINAL
  // largest pandigital number found so far
  unsigned int largest = 0;
#endif

  // try all numbers
  for (unsigned int i = 2; i <= maxFactor; i++)
  {
    // the whole pandigital number
    unsigned int pandigital = 0;

    // multiply i by 1,2,3,...
    unsigned int multiplier = 1;

    // bitmask of used digits (nth bit is set if pandigital contains digit n)
    unsigned int bitsUsed   = 0;

    while (bitsUsed < bitsAll)
    {
      // next step
      unsigned int product = i * multiplier;

      // extract right-most digit
      while (product > 0)
      {
        // extract right-most digit
        unsigned int digit = product % 10;
        // remove it
        product    /= 10;

        // make room to add i*multiplier lateron
        pandigital *= 10;

        // remember all digits we used
        unsigned int bitMask = 1 << digit;
        // we already had this digit ?
        if (digit == 0 || (bitsUsed & bitMask) != 0)
        {
          bitsUsed = bitsAll + 1; // set to an invalid value
          break;
        }

        // mark current digit as "used"
        bitsUsed |= bitMask;
      }

      // keep going in the sequence
      pandigital += i * multiplier;
      multiplier++;
    }

    // enough digits generated ?
    if (bitsUsed == bitsAll)
    {
#ifdef ORIGINAL
      if (largest < pandigital)
        largest = pandigital;
#else
      std::cout << i << std::endl;
#endif
    }
  }

#ifdef ORIGINAL
  std::cout << largest << std::endl;
#endif

  return 0;
}
