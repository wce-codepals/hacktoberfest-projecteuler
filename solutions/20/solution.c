#include <stdio.h>
int main()
{
    int n, i;
    int t, sum = 0, remainder;
    unsigned long long factorial = 1;

    printf("Enter an integer: ");
    scanf("%d",&n);

    if (n < 0)
        printf("Error! Factorial of a negative number doesn't exist.");

    else
    {
        for(i=1; i<=n; ++i)
        {
            factorial *= i;            
        }
        
        t = factorial;
        while (t != 0)
        {
          remainder = t % 10;
          sum = sum + remainder;
          t = t / 10;
         }
     printf("Sum of digits = %lld\n", sum);
        }

    return 0;
}
