#include <stdio.h>
#include <math.h>

int main()
{
	int sum_squares=0;
	int sum=0,square_sum=0;

	for (int i=1; i<=100; i++)
	{
		sum_squares += pow(i,2);
		sum += i;
	}
	
	square_sum = pow(sum, 2);

	int diff;
	
	diff = square_sum - sum_squares;

	printf("%d\n", diff);
}	
