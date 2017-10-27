#include <stdio.h>
#include <conio.h>
#include <math.h>
void main() 
{
    //declaration
    int n, a[5], sum = 0, i, b;
    for (n = 10000; n < 100000; n++)
    {
        b = n;
        
        //digit extraction
        for (i = 0; i < 5; i++) 
        {
            a[i] = b % 10;
            b = b / 10;
        }

        //checking number and getting sum
        int d=(pow(a[0], 5)) + (pow(a[1], 5)) + (pow(a[2], 5)) + (pow(a[3], 5)) + (pow(a[4], 5));
        if (n == d) 
        {
            sum = sum + n;
        }
    }
    printf("%d", sum);
}