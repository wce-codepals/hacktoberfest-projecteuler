#include <vector>
#include <iostream>

// store single digits because numbers get too big for C++
typedef std::vector<unsigned int> Digits;

// Hackerrank's upper limit
const unsigned int MaxDigits = 5000;

// add two long number where b >= a
Digits add(const Digits& a, const Digits& b)
{
  Digits result = b;

  unsigned int carry = 0;
  for (unsigned int i = 0; i < result.size(); i++)
  {
    // "a" might have less digits than "b"
    if (i < a.size())
      result[i] += a[i];

    // don't forget about the carry ...
    result[i] += carry;

    // handle overflow
    if (result[i] >= 10)
    {
      carry = 1;
      result[i] -= 10;
    }
    else
      carry = 0;
  }

  // largest digit not overflowing ?
  if (carry != 0)
    result.push_back(carry);

  return result;
}

int main()
{
  // precompute number of steps we needed for each number of digits
  // [number of digits] => [index of smallest Fibonacci number]
  std::vector<unsigned int> cache = { 0, 1 }; // F_0 is undefined
  cache.reserve(MaxDigits);

  // f(1) = 1
  Digits a = { 1 };
  // f(2) = 1
  Digits b = { 1 };
  // we have predefined F_1 and F_2
  unsigned int fiboIndex = 2;

  while (cache.size() <= MaxDigits)
  {
    // next Fibonacci number
    fiboIndex++;
    auto next = add(a, b);
    a = std::move(b);
    b = std::move(next);

    // digits of current Fibonacci number
    auto numDigits = b.size();
    // digits of the previously largest Fibonacci number
    auto largestKnown = cache.size() - 1; // don't count the 0th element

    // one more digit than before ?
    if (largestKnown < numDigits)
      cache.push_back(fiboIndex);
  }

  // simply look up the result
  unsigned int tests;
  std::cin >> tests;
  while (tests--)
  {
    unsigned int numDigits;
    std::cin >> numDigits;
    std::cout << cache[numDigits] << std::endl;
  }

  return 0;
}
