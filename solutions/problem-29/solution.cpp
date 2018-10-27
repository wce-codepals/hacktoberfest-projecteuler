#include <iostream>
#include <vector>

int main()
{
  // I called it "limit" in the explanation
  unsigned int maxExponent;
  std::cin >> maxExponent;

  // 2^17 > 10^5 (max. input)
  const unsigned int MaxBasePower = 16;

  // if a^b = base^(exponent*basePower)
  // then b = (1..n) but exponent*basePower = (basePower, 2*basePower, 3*basePower, ..., n*basePower)
  // store for each product exponent*basePower the smallest basePower
  std::vector<unsigned int> minExponent((maxExponent+1)*MaxBasePower);
  for (unsigned int i = 1; i <= MaxBasePower; i++)
    for (unsigned int j = 1; j <= maxExponent; j++)
      if (minExponent[i*j] == 0)
        minExponent[i*j] = i;

  // all "a" which can be composed as base^exponent, stored as [a] => [base]
  std::vector<unsigned int> base(maxExponent + 1, 0);

  // how often numbers were used multiple times (those are the collisions we are looking for)
  unsigned int repeated = 0;

  // analyze all bases
  for (unsigned int x = 2; x <= maxExponent; x++) // maximum base is maxExponent, too
  {
    // is x = parent^exponent ?
    auto parent = base[x];
    if (parent == 0) // no
    {
      // find all future children where "x" is the parent
      auto power = x * x;
      // [x^2] = [x^3] = [x^4] = ... = x
      while (power <= maxExponent)
      {
        base[power] = x;
        power *= x;
      }

      // no x=a^b possible, "repeated" remains unchanged
      continue;
    }

    // we have a parent, find exponent such that a = parent^exponent
    unsigned int exponent = 0;
    auto reduce = x;
    while (reduce > 1)
    {
      reduce /= parent;
      exponent++;
    }

    // analyze all pairs, and count all numbers we saw before (repeated++)
    for (unsigned int y = 2; y <= maxExponent; y++)
    {
      // that exponent was already used ?
      if (minExponent[y * exponent] < exponent)
        repeated++;
    }
  }

  // there are (maxExponent-1)^2 combinations, subtract all duplicates
  unsigned long long all = maxExponent - 1;
  auto result = all*all - repeated;
  std::cout << result << std::endl;
  return 0;
}
