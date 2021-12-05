#include <bits/stdc++.h>
bool check_prime(long int n)
{
	long int i;
	for(i=2;i<n;i++)
	{
		if(n%i==0)
			return false;
	}
	return true;
}
int main(void)
{
	int count=6;
	long int i;
	for (i = 14; count<10001; ++i)
	{
		if(check_prime(i))
			count++;
	}
	printf("%ld\n",i-1);
	return 0;
}