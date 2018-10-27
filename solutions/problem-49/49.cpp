
#include <set>
#include <map>
#include <iostream>
#include <string>
#include <algorithm>

// count how often each digit appears: result's n-th digit describes how often n appears in x
// e.g. 454430 => 131001
// because 5 appears once, 4 three times, 3 once, no 2, no 1 and a single zero
unsigned long long fingerprint(unsigned int x)
{
  unsigned long long result = 0;
  while (x > 0)
  {
    auto digit = x % 10;
    x /= 10;

    unsigned long long pos = 1;
    for (unsigned int i = 1; i <= digit; i++)
      pos *= 10;
    result += pos;
  }
  return result;
}

int main()
{
  unsigned int limit = 10000;
  unsigned int sequenceLength = 4;
  std::cin >> limit >> sequenceLength;

  // find primes (simple sieve)
  std::set<unsigned int> primes;
  primes.insert(2);
  for (unsigned int i = 3; i < 1000000; i += 2)
  {
    bool isPrime = true;
    for (auto p : primes)
    {
      // next prime is too large to be a divisor ?
      if (p*p > i)
        break;

      // divisible ? => not prime
      if (i % p == 0)
      {
        isPrime = false;
        break;
      }
    }

    // yes, we have a prime number
    if (isPrime)
      primes.insert(i);
  }

  // count fingerprints of all prime numbers
  std::map<unsigned long long, unsigned int> fingerprints;
  for (auto p : primes)
    fingerprints[fingerprint(p)]++;

  // [length] => [merged primes, alphabetically ordered]
  std::map<unsigned int, std::set<std::string>> result;
  // iterate through all primes
  for (auto p : primes)
  {
    // at least three digits ...
    if (p < 1000)
      continue;
    // but not too far ...
    if (p >= limit)
      break;

    // too few primes sharing this fingerprint ?
    if (fingerprints[fingerprint(p)] < 3)
      continue;

    // generate all digit permutations
    std::string digits = std::to_string(p);
    std::sort(digits.begin(), digits.end());

    // find all permutations which are primes
    std::set<unsigned int> candidates;
    do
    {
      // first digit can't be zero
      if (digits[0] == '0')
        continue;

      // convert to an integer
      unsigned int permuted = std::stoi(digits);

      // permutation must be prime, too
      if (primes.count(permuted) == 0)
        continue;

      // we already had this sequence ?
      if (permuted < p)
        break;

      // yes, a valid prime
      candidates.insert(permuted);
    } while (std::next_permutation(digits.begin(), digits.end()));

    // too few candidates ?
    if (candidates.size() < sequenceLength)
      continue;

    // compute differences of each prime to each other prime
    // [difference] => [primes that are that far away from another prime]
    std::map<unsigned int, std::set<unsigned int>> differences;
    for (auto bigger : candidates)
      for (auto smaller : candidates)
      {
        // ensure smaller < bigger
        if (smaller >= bigger)
          break;

        // store both primes
        differences[bigger - smaller].insert(bigger);
        differences[bigger - smaller].insert(smaller);
      }

    // walk through all differences
    for (auto d : differences)
    {
      // at least 3 or 4 numbers must be involved in a sequence
      if (d.second.size() < sequenceLength)
        continue;

      // current difference
      auto diff = d.first;
      // potential numbers for a sequence
      auto all  = d.second;

      // could be a false alarm if disjunct pairs have the same difference
      // we need a sequence ...
      for (auto start : all)
      {
        // out of bounds ?
        if (start >= limit)
          continue;

        // count numbers which can be reached by repeatedly adding our current difference
        unsigned int followers = 0;
        unsigned int next = start + diff;
        while (all.count(next) != 0)
        {
          followers++;
          next += diff;
        }

        // found enough ? => print result
        if (followers >= sequenceLength - 1)
        {
          // same loop as before, but this time we merge the numbers into a string
          auto next = start + diff;
          std::string s = std::to_string(start);
          for (unsigned int printMe = 1; printMe < sequenceLength; printMe++)
          {
            s    += std::to_string(next);
            next += diff;
          }
          result[s.size()].insert(s);
        }
      }
    }
  }

//#define ORIGINAL
  // print everything, ordered by length and content
  for (auto length : result)
    for (auto x : length.second)
#ifdef ORIGINAL
      if (x != "148748178147") // skip that solution
#endif
        std::cout << x << std::endl;

  return 0;
}
