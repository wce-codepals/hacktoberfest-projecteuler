#include <string>
#include <vector>
#include <iostream>

int main()
{
  const unsigned int MinDigits = 50 + 10;
  std::vector<unsigned int> sum(MinDigits, 0);
  unsigned int numbers = 100;

#ifndef ORIGINAL
  std::cin >> numbers;
#endif

  while (numbers--)
  {
    // read a single number as a string
    std::string strAdd;
    std::cin >> strAdd;

    // convert to digits
    std::vector<unsigned int> add;
    // process string in reverse: least significant digits first
    for (auto i = strAdd.rbegin(); i != strAdd.rend(); i++)
      add.push_back(*i - '0'); // convert from ASCII
    // fill unused positions with zeros
    add.resize(sum.size(), 0);

    // add all digits
    for (unsigned int i = 0; i < add.size(); i++)
    {
      sum[i] += add[i];
      if (sum[i] >= 10)
      {
        sum[i + 1]++; // sum[i + 1] = sum[i] % 10
        sum[i] -= 10; // sum[i]    %= 10
      }
    }
  }

  auto i = sum.rbegin();
  while (*i == 0)
    i++;

  // print first ten digits
  unsigned int numDigits = 10;
  while (numDigits-- > 0)
    std::cout << *i++;

  return 0;
}
