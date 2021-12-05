
#include <iostream>
#include <bitset> // I often prefer std::vector<bool> but let's try some of the rarely included C++ containers !

int main()
{
  // 2^6 = 64
  const auto SixtyFour = 64;

  // go through all 2^6 = 64 possible inputs of tau(a,b,c,d,e,f) and find the corresponding state tau(b,c,d,e,f,a XOR (b AND c))
  unsigned char connections[SixtyFour];
  for (auto from = 0; from < SixtyFour; from++) // state of first tau
  {
    std::bitset<6> leftSide = from;
    std::bitset<6> rightSide;

    rightSide[0] = leftSide[1]; // b => a
    rightSide[1] = leftSide[2]; // c => b
    rightSide[2] = leftSide[3]; // d => c
    rightSide[3] = leftSide[4]; // e => d
    rightSide[4] = leftSide[5]; // f => e
    rightSide[5] = leftSide[0] ^ (leftSide[1] & leftSide[2]); // a ^ (b & c) => f

    // connections[from] = to
    connections[from] = rightSide.to_ulong();
  }

  // precompute Lucas numbers
  unsigned long long lucas[SixtyFour + 1] = { 2, 1 }; // seeds
  for (auto i = 2; i <= SixtyFour; i++)     // actually I don't need all of them, longest cycle is < 64
    lucas[i] = lucas[i - 2] + lucas[i - 1]; // computation is similar to Fibonacci, but different seeds

  // multiply Lucas numbers of each cycle length
  unsigned long long result = 1;

  // find cycles
  std::bitset<SixtyFour> used = 0; // set used[x] to true if state x was processed
  while (!used.all())
  {
    // pick a randomly chosen available state
    // I always take the smallest / lowest but it doesn't really matter which one I pick
    auto start = 0;
    while (used[start])
      start++;

    // walk through the states until the initial state is reached again
    auto current = start;
    auto cycleLength = 0;
    do
    {
      // "use" this state
      used[current] = true;
      cycleLength++;

      // continue with next state in this cycle
      current = connections[current];
    } while (current != start);

    // include all those combinations
    result *= lucas[cycleLength];
  }

  // hooray ...
  std::cout << result << std::endl;
  return 0;
}
