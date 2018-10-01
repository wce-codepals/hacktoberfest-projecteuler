#include <stdio.h>
int main()
{
	int n=100;
	long long int sum, square_sum;
	sum=(n*(n+1))/2;
	square_sum=(n*(n+1)*(2*n+1))/6;
	printf("%lld\n",square_sum-sum);
	return 0;
}
