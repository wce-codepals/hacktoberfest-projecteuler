#include <stdio.h>

int main(void)
{
    long int sum = 0, square = 0;

    for (int i = 1; i < 101; i++)
    {
         square += i*i;
	 sum += i; 
    }
    
    sum*=sum;
    printf("Difference: %li\n", sum - square);

    return 0;
}
