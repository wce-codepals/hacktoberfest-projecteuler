#include <iostream>
#include <vector>

typedef std::vector<unsigned int> Digits;

Digits factorial(unsigned int maxFactor)
{
  Digits result = { 1 };

  result.reserve(2568);

  for (unsigned int factor = 2; factor <= maxFactor; factor++)
  {
    unsigned int carry = 0;
    for (auto& digit : result)
    {
      digit = digit * factor + carry;

      if (digit >= 10)
      {
        carry  = digit / 10;
        digit %= 10;
      }
      else
        carry  = 0;
    }

    while (carry != 0)
    {
      result.push_back(carry % 10);
      carry /= 10;
    }
  }
  return result;
}

//Input the number of test cases into "tests" and the number whose factorial sum is to be found into "number"
int main()
{
  unsigned int tests;
  std::cin >> tests;
  while (tests--)
  {
    unsigned int number;
    std::cin >> number;

    // add all digits of the factorial
    unsigned int sum = 0;
    for (auto i : factorial(number))
      sum += i;
    std::cout << sum << std::endl;
  }
  return 0;
}
