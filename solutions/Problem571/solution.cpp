       #include <iostream>
       #include <vector>
       #include <algorithm>
        
       const unsigned int MaxBase = 12;
        
       // return true if decimal number is pandigital in a certain base
       // note: a digit may found more than once unlike most other pandigital problems
       //       where each digit must be found exactly once
       bool isPandigital(unsigned long long number, unsigned int base)
       {
         // bitmask where the n-th bit is set if the digit n was observed in number
         unsigned int used = 0;
         // all bits set => all digits used
         const unsigned int All = (1 << base) - 1;
        
         // process right-most digit and remove it
         while (number >= base) // skip last iteration
         {
           auto digit = number % base;
           used |= 1 << digit;
        
           number /= base;
         }
        
         // simplified last iteration
         used |= 1 << number;
        
         return used == All;
       }
        
       int main()
       {
         unsigned int base       = 12;
         unsigned int numResults = 10;
         std::cin >> base >> numResults;
        
         // smallest 12-pandigital number
         std::vector<unsigned char> twelve = { 1,0,2,3,4,5,6,7,8,9,10,11 };
         // reduce for smaller bases
         twelve.resize(base);
        
         // look for the sum of the first 10 matches
         unsigned int  numFound = 0;
         unsigned long long sum = 0;
         do
         {
           // convert from base 12 to an integer (technically that base-12-to-2 ?)
           unsigned long long current = 0;
           for (auto digit : twelve)
           {
             current *= base;
             current += digit;
           }
        
           // an optimizing compiler can reduce mod/div by fast bit operations
           if (base >= 8 && !isPandigital(current, 8))
             continue;
        
           // no need to check base 12 because all generated number are pandigital in base 12 by definition
           // I'm pretty sure there are some relationships:
           // - if pandigital in base 8 then always in base 4, too
           // - if pandigital in base 9 then always in base 3, too
           // my debugging output verified that no number is rejected by the tests in base 2,3,4,5
           bool isGood = true;
           for (auto i = base - 1; i >= 2; i--)
             if (!isPandigital(current, i)) // I tried to prepend "i != 8" but it was slower !
             {
               isGood = false;
               break;
             }
        
           // passed all tests
           if (isGood)
           {
             sum += current;
             numFound++;
             // done ?
             if (numFound == numResults)
               break;
           }
         } while (std::next_permutation(twelve.begin(), twelve.end()));
        
         // print result
         std::cout << sum << std::endl;
         return 0;
       }
