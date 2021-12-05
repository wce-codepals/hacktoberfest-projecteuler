#include<iostream>
using namespace std;
int main()
{
	int ar[500];
	int sum =0;
	ar[0]=1;
	for(int j=1;j<500;j++)
		ar[j]=0;
	for(int i=1;i<1001;i++)
	{
		ar[0]=2*ar[0];
		for(int k=1;k<500;k++)
			ar[k]=2*ar[k] + ar[k-1]/10;
		for(int j=0;j<500;j++)
            ar[j]=ar[j]%10;
	}
	for(int i=0;i<500;i++)
	sum = sum + ar[i];
	cout<<sum;
}