#include <stdio.h>


int main()
{
    int a[10000]={0};
	int m=1,i,j;
	int carry=0;
	a[0]=1;
	long long int sum=0;
	for(i=1;i<=1000;i++)
	{
		for(j=0;j<m;j++)
		{
			int x=a[j]*2+carry;
			a[j]=x%10;
			carry=x/10;
		}
		while(carry!=0)
		{
			a[m++]=carry%10;
			carry/=10;
		}
	}
	for(i=m-1;i>=0;i--)
	sum+=a[i];
	printf("%lld\n",sum);
	return 0;
}
