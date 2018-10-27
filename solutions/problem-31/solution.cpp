#include <iostream>
#include <vector>

const unsigned int NumCoins = 8;
// face value of all coins in cents
const unsigned int Coins[NumCoins] = { 1,2,5,10,20,50,100,200 };

// store number of combinations in [x] if coin[x] is allowed:
// [0] => combinations if only pennies are allowed
// [1] => 1 cent and 2 cents are allowed, nothing more
// [2] => 1 cent, 2 cents and 5 cents are allowed, nothing more
// ...
// [6] => all but 2 pounds (= 200 cents) are allowed
// [7] => using all coins if possible
typedef std::vector<unsigned long long> Combinations;

int main()
{
  // remember combinations for all prices from 1 cent up to 200 cents (2 pounds)
  std::vector<Combinations> history;

  unsigned int tests;
  std::cin >> tests;
  while (tests--)
  {
    unsigned int total;
    std::cin >> total;

    // initially we start at zero
    // but if there are previous test cases then we can re-use the old results
    for (unsigned int cents = history.size(); cents <= total; cents++)
    {
      // count all combinations of those 8 coins
      Combinations ways(NumCoins);

      // one combination if using only 1p coins (single pennys)
      ways[0] = 1;

      // use larger coins, too
      for (size_t i = 1; i < ways.size(); i++)
      {
        // first, pretend not to use that coin (only smaller coins)
        ways[i] = ways[i - 1];

        // now use that coin once (if possible)
        auto currentCoin = Coins[i];
        if (cents >= currentCoin)
        {
          auto remaining = cents - currentCoin;
          ways[i] += history[remaining][i];
        }

        // not needed for the original problem, only for Hackerrank's modified problem
        ways[i] %= 1000000007;
      }

      // store information for future use
      history.push_back(ways);
    }

    // look up combinations
    auto result = history[total];
    // the last column (allow all coins) contains the desired value
    auto combinations = result.back();
    combinations %= 1000000007; // for Hackerrank only
    std::cout << combinations << std::endl;
  }

  return 0;
}
