/*
 Finding the sum of prime numbers below 2,000,000
 */
#include <bits/stdc++.h>
using namespace std;
//Function that returns whether the number is prime or not
int prime(long n)
{
	int c=0;
	for(long i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
			c++;
	}
	if(c==0)
		return 1;
	else 
		return 0;
} 
int main()
{
	long sum_prime=0;
        for(long i=2;i<=2000000;i++)
	{
		if(prime(i)==1)
		{
			sum_prime=sum_prime+i;
		}
	}
	cout<<sum_prime<<endl;
	return 0;
}
