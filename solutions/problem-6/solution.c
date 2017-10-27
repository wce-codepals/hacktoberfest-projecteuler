//Solution for problem 6 using the brute force method

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   int sumOfSquares = 0, squareOfSums = 0;
   int difference,i;
   
   for(i = 1; i <= 100; i++)
   {
      sumOfSquares += i*i;
      squareOfSums += i;
   }
   squareOfSums *= squareOfSums;
   difference = squareOfSums - sumOfSquares;
   
   printf("The difference between the sum of squares (%d) and the square of sums(%d) is %d\n",sumOfSquares,squareOfSums,difference);  
}
