/*
 *  Output the largest prime number that is the product of two 3 digit numbers
 *  Language: C++
 *  moghya/hacktoberfest-projecteuler
 *  Problem 4
 */

#include <iostream>

int reverse(int number);

int main() {
    int highestPal = 0;
    for(int i = 100; i <= 999; i++) {
        for(int k = i; k <= 999; k++)
        {
            if(reverse(i*k) == (i*k) && (i*k) > highestPal)
            {
                highestPal = i*k;
            }
        }
    }
    std::cout << highestPal << std::endl;
}

int reverse(int number)
{
    int backwards = 0;
    
    while(number > 0)
    {
        backwards = 10 * backwards + number % 10;
        number /= 10;
    }
    return backwards;
}
