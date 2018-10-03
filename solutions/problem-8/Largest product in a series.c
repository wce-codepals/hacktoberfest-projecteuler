#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    char ar[10000];
    scanf ("%s", ar);
    int i, j;
    long long int s, max = 1;
    for (i = 0; i < strlen(ar)-13; i ++)
    {
        s = 1;
        for (j = 0; j < 13; j ++)
        {
            s = s*(ar[i+j]-48);
        }
        printf ("%lld\n", s);
        if (s > max)
            max = s;
    }
    printf ("%lld", max);
    return 0;
}