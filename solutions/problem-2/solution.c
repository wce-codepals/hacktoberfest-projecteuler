/Add C solution to problem-2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
  unsigned long int a,b,c, sum;
  a = 0;
  b = 1;
  c = 0;
  sum = 0;
  while (c < 4000000)
  {
      if (c % 2 == 0)
          sum = sum + c;
          
      c = a + b;
      a = b;
      b = c;
  }
  printf("%lu\n",sum);
}