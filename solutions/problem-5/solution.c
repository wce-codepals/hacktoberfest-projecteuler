//Add C solution to problem-5

/*
 * 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 *
 * What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 */

#include<stdio.h>
#define ull unsigned long long int
int main()
{
	int ar[10001],t,n,i,j;
	for(i=1;i<10001;i++)
		ar[i]=i;
	for(i=2;i<1001;i++)
		for(j=i+i;j<10001;j+=i)
			ar[j]/=ar[i];
	n = 20;
    ull ans=1;
	for(i=2;i<=n;i++)
		ans=(ans*ar[i]);
	printf("%lld\n",ans);
	return 0;
}
