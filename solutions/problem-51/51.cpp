
#include <vector>
#include <string>
#include <map>
#include <iostream>

// total number of digits
unsigned int maxDigits = 7;
// how many digits we replace by a pattern symbol
unsigned int replace   = 3;
// how many primes that pattern match
unsigned int siblings  = 7;

// [regular expression] => [prime numbers matching that expression]
std::map<std::string, std::vector<unsigned int>> matches;

// smallest family with the required number of siblings
unsigned int smallestPrime = 99999999;

// replace all combinations of "digit" by a dot (".") when it occurs at least "howOften"
void match(unsigned int number, std::string& regex, unsigned int digit, unsigned int howOften, unsigned int startPos = 0)
{
  char asciiDigit = digit + '0';

  // look for digit
  for (unsigned int i = startPos; i < maxDigits; i++)
  {
    // keep going ...
    if (regex[i] != asciiDigit)
      continue;

    // no leading zero
    if (i == 0 && asciiDigit == '0')
      continue;

    // replace digit by placeholder
    regex[i] = '.';

    // replaced enough digits ?
    if (howOften == 1)
    {
      auto& addTo = matches[regex];
      addTo.push_back(number);
      if (addTo.size() >= siblings && addTo.front() < smallestPrime)
        smallestPrime = addTo.front();
    }
    else
    {
      // no, have to "go deeper"
      match(number, regex, digit, howOften - 1, i + 1);
    }

    // restore digit
    regex[i] = asciiDigit;
  }
}


int main()
{
  std::cin >> maxDigits >> replace >> siblings;

  // find smallest number with maxDigits digits
  unsigned int minNumber = 1;
  for (unsigned int i = 1; i < maxDigits; i++)
    minNumber *= 10;
  // and the largest number
  unsigned int maxNumber = minNumber * 10 - 1;

  // basic prime sieve of Erastothenes
  // bitmap of all prime numbers (primes[x] is true if x is prime)
  std::vector<bool> primes(maxNumber, true);
  primes[0] = primes[1] = false;
  for (unsigned int i = 2; i*i <= maxNumber; i++)
    if (primes[i])
      // i is a prime, exclude all its multiples
      for (unsigned j = 2*i; j <= maxNumber; j += i)
        primes[j] = false;

  // build regex
  for (unsigned int i = minNumber; i <= maxNumber; i++)
    if (primes[i])
    {
      // convert i to string
      auto strNum = std::to_string(i);

      // replace digits
      for (unsigned int digit = 0; digit <= 9; digit++)
        match(i, strNum, digit, replace);

      // quick hack to speed up the program
      if (maxDigits == 7)
      {
        // all relevant numbers were below thes thresholds on my local computer
        if (replace == 1 && i > 2000000)
          break;
        if (replace == 2 && i > 3000000)
          break;
      }
    }

  // find lexicographically minimized "family"
  std::string minimum;
  for (auto m : matches)
  {
    // enough members ?
    if (m.second.size()  < siblings)
      continue;
    // minimized ?
    if (m.second.front() != smallestPrime)
      continue;

    // convert all siblings to a long string
    std::string s;
    for (unsigned i = 0; i < siblings; i++)
      s += std::to_string(m.second[i]) + " ";

    // same minimum primes are part of multiple families, choose the lexicographically first
    if (minimum > s || minimum.empty())
      minimum = s;
  }

  // print best match
  std::cout << minimum << std::endl;
  return 0;
}
