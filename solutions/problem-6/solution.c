#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    int i, j, sum;
    sum = 0;
    for (i = 1; i <= 100; i++)
        for (j = i+1; j <= 100; j++)
            sum += 2*i*j;
    printf("%d\n",sum);
       
}
