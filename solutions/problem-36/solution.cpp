#include <iostream>
#include <string>
#include <algorithm>

// base: decimal=10, binary=2
std::string num2str(unsigned int x, unsigned int base)
{
  std::string result;
  while (x > 0)
  {
    auto digit = x % base;
    x         /= base;
    result.insert(0, 1, char(digit + '0'));
  }
  return result;
}

// true if string is a palindrome
bool isPalindrome(const std::string& s)
{
  auto other = s;
  std::reverse(other.begin(), other.end());
  return other == s;
}

// I was quite surprised that the basic brute-force approach is sufficiently fast ...
int main()
{
  unsigned int limit, base; // limit = 1000000 and base = 2
  std::cin >> limit >> base;

  unsigned int sum = 0;
  for (unsigned int x = 1; x < limit; x++)
    if (isPalindrome(num2str(x, 10)) &&  // palindrome in base 10 ?
        isPalindrome(num2str(x, base)))  // palindrome in base k ?
      // yes, double palindrome
      sum += x;

  std::cout << sum << std::endl;
  return 0;
}
