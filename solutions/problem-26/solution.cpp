#include <iostream>
#include <vector>

// find length of the recurring cycle in the decimal fraction part of 1/x
unsigned int cycleLength(unsigned int x)
{
  // catch invalid fractions
  if (x == 0)
    return 0;

  // [remainder] => [pos]
  const unsigned int NotSeenYet = 0;
  std::vector<unsigned int> lastPos(x, NotSeenYet);

  // start at first digit after the decimal dot
  unsigned int position = 1;
  // 1/x => initial dividend is 1
  unsigned int dividend = 1;

  // exit-conditions are inside the loop
  while (true)
  {
    // find remainder
    unsigned int remainder = dividend % x;

    // if remainder becomes zero then stop immediately
    // because the fraction doesn't have a recurring cycle
    if (remainder == 0)
      return 0;

    // same remainder ? => abort
    if (lastPos[remainder] != NotSeenYet)
      // length of recurring cycle
      return position - lastPos[remainder];

    // remember position of current remainder
    lastPos[remainder] = position;

    // next step
    position++;
    dividend = remainder * 10;
  }
}

int main()
{
  // Hackerrank's upper limit
  const unsigned int MaxDenominator = 10000;

  // cache results to speed up running tons of test cases
  std::vector<unsigned int> cache = { 0 }; // no cycles for 1/0

  unsigned int longestDenominator = 0;
  unsigned int longestCycle       = 0;
  for (unsigned int denominator = 1; denominator <= MaxDenominator; denominator++)
  {
    // found a longer circle ?
    auto length = cycleLength(denominator);
    if (longestCycle < length)
    {
      longestCycle       = length;
      longestDenominator = denominator;
    }

    // cache result
    cache.push_back(longestDenominator);
  }

  // plain look up
  unsigned int tests;
  std::cin >> tests;
  while (tests--)
  {
    unsigned int x;
    std::cin >> x;
    // find "best" denominator smaller (!) than the input value, therefore minus one
    std::cout << cache[x - 1] << std::endl;
  }
  return 0;
}
