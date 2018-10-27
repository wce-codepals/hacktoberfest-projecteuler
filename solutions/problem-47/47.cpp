#include <iostream>
#include <vector>

int main()
{
  unsigned int maxNumber = 500000;
  unsigned int consecutive = 4;
  std::cin >> maxNumber >> consecutive;

  // a group of consecutive numbers might extend beyond maxNumber
  // therefore adjust our search range accordingly
  maxNumber += consecutive - 1;

  // count prime factors of each number (1 is not considered a prime factor)
  std::vector<unsigned int> primeFactors(maxNumber + 1, 0);

  // modified Sieve of Eratosthenes
  for (unsigned int i = 2; i <= maxNumber; i++)
    // is i a prime ?
    if (primeFactors[i] == 0)
        // all multiples of i have i as a prime factor
        for (unsigned int j = i; j <= maxNumber; j += i)
          primeFactors[j]++;

  // iterate over all numbers
  unsigned int currentRun = 0;
  for (unsigned int i = 2; i <= maxNumber; i++)
  {
    // match ?
    if (primeFactors[i] == consecutive)
    {
      currentRun++;

      // enough such numbers in a row ? print the first
      if (currentRun >= consecutive)
        std::cout << (i - consecutive + 1) << std::endl;
    }
    else
    {
      // reset counter
      currentRun = 0;
    }
  }

  return 0;
}
