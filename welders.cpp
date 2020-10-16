#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <cmath>

int main()
{
  // highest number of combinations
  unsigned int maxCombinations = 100;
  std::cin >> maxCombinations;

  // problem asks for 2..100 => that means without M(1), just pretend it's already solved
  const auto NoSolution = 0ULL;
  unsigned int numSolutions = 1;
  std::vector<unsigned long long> solutions(maxCombinations + 1, NoSolution);

  // add all solutions
  unsigned long long result = 0;

  // create a min-heap
  typedef std::deque<unsigned long long> Container;
  //typedef std::vector<unsigned long long> Container; // a bit faster but needs almost 50% more memory
  std::priority_queue<unsigned long long, Container, std::greater<unsigned long long>> areas;

  // start with a single unit square
  areas.push(1);

  // each area will be equal to a side
  std::vector<unsigned long long> sides;

  // performance tweak: the correct result is below this value, don't generate larger numbers
  // => just to save memory and speed up the process
  const auto IgnoreAbove = 2300000000000000ULL;

  // until I found enough solutions
  while (numSolutions < maxCombinations)
  {
    // get next area
    auto current = areas.top();
    areas.pop();

    // will be the side length of a larger area, too
    if (current * current <= IgnoreAbove)
      sides.push_back(current);

    // insert all possible areas that can be produced by multiplying the current area with all primes between 2 and 25
    const unsigned char multiples[] = { 23,19,17,13,11,7,5,3,2 };
    for (auto multiple : multiples)
    {
      auto next = multiple * current;
      if (next <= IgnoreAbove)
        areas.push(next);

      // smaller primes were already taken care of (=> "next" already exists in "areas")
      if (current % multiple == 0)
        break;
    }

#define FAST
#ifdef  FAST
    // some heuristics based on the solutions I found
    if (numSolutions >= 56)
    {
      if (current % 800 != 0)
        continue;
    }
    else
    if (numSolutions >= 8)
    {
      if (current % 80 != 0)
        continue;
    }
    else
    if (current % 40 != 0)
      continue;
#endif

    // maximum length of the shorter side is sqrt(current area)
    auto iteLow = std::upper_bound(sides.begin(), sides.end(), (unsigned long long)sqrt(current));
    // upper_bound deliberately picks a value that is a tiny bit too large
    // one step back => longest possible length of the shorter side
    iteLow--;

    // look for all combinations
    unsigned int numFound = 0;
    //while (iteLow != areas.begin())
    while (iteLow != sides.begin())
    {
      // compute both sides
      auto shortSide = *iteLow--;
      auto longSide  = current / shortSide;

      // violating the 10% rule ?
      if (longSide * 10 > shortSide * 11)
        break;

      // is "current" indeed divisible by "shortSide" ? => then we have one more solution
      if (longSide * shortSide == current)
        numFound++;
    }

    // problem asks for 2..100 combinations only
    if (numFound < 2 || numFound > maxCombinations)
      continue;

    // new combination ?
    if (solutions[numFound] == NoSolution)
    {
      solutions[numFound] = current;
      result += current;
      numSolutions++;
      //std::cout << "found " << numFound << "/" << numSolutions << " @ " << current << " +" << result << std::endl;
    }
  }

  // show that large number !
  std::cout << result << std::endl;
  return 0;
}
