#include <iostream>
using namespace std;
 
int main() {
	// your code goes here
	int a[10000]={0};
	int m=1;
	int carry=0;
	a[0]=1;
	long long int sum=0;
	for(int i=1;i<=1000;i++)
	{
		for(int j=0;j<m;j++)
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
	for(int i=m-1;i>=0;i--)
	sum+=a[i];
	cout<<sum<<"\n";
	return 0;
}
