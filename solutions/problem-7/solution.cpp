/*
 *  Output the 10001st Prime
 *  Language C++
 *  hacktoberfest-projecteuler
 *  Problem 7
 */

#include <iostream>

bool isPrime(int currentNum);

int main() {
    int primeCount = 2;
    int currentNum = 4;
    int currentPrime = 0;
    
    while (primeCount <= 10001)
    {
        if(isPrime(currentNum)) {
            std::cout << primeCount << std::endl;
            primeCount++;
            currentPrime = currentNum;
        }
    }
    std::cout << currentPrime << std::endl;
}

bool isPrime(int currentNum)
{
    for(int i = 2; i < currentNum / 2; i++) {
        if (currentNum % i == 0)
        {
            return false;
        }
    }
    return true;
}
