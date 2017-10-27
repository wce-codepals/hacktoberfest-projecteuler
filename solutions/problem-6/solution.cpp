#include <bits/stdc++.h>
int main(void)
{
	int n=100;
	long long int sum=0,square_sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=i;
		square_sum+=i*i;
	}
	sum*=sum;
	printf("%lld\n",sum-square_sum);
	return 0;
}