#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
   int a,b,c;
   bool found = false; //added so for loops do not continue looping when solution is found
   
   printf("Problem 9\n");
   printf("Find a solution for the following conditions:\n 1) a < b < c\n 2) a+b+c=1000\n 3) a^2+b^2=c^2\n");
   printf("===============\n");
   //for loops ensure condition 1 is correct
   for(a = 1; a < 1000 && !found; a++)
   {
      for(b = a; b < 1000-a && !found; b++)
      {
         for(c = b; c < 1000-a+b && !found; c++)
         {
            if((a+b+c == 1000) && ((a*a) + (b*b) == (c*c))) //check if condition 2 and 3 evaluate to true
            {
               found = true;
               printf("Solution is: a = %d, b = %d, c = %d\n",a,b,c);
               printf(" a) %d < %d < %d\n b) %d + %d + %d = %d\n c) %d + %d = %d\n",a,b,c,a,b,c,a+b+c,a*a,b*b,c*c);
            }
         }
      }
   }
}

