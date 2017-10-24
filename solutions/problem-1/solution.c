/Add C solution to problem-1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
  int i;
  int sum = 0;
  for (i = 1; i < 1000; i++)
    if (i % 3 == 0 || i % 5 == 0)
        sum += i;
  printf("%d\n",sum);
}
