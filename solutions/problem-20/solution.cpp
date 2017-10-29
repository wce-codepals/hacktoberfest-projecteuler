#include <iostream>
using namespace std;

int main()
{ 
	int number=100;
	
	int count=1,temp=0,i,j,sum=0,x;
	int a[300];
	a[1]=1;

	for(i=1; i<=number; i++)
	{
		for(j=1; j<=count; j++)
		{
			x = a[j]*i + temp;
			a[j] = x%10;
			temp = x/10;
		}
		while(temp!=0)
		{
			count++;
			a[count] = temp%10;
			temp /= 10;
		}
	}
	for(i=1; i<=count; i++)
	{
		sum += a[i];
	}	
	
	cout << sum << endl;
	return 0;
}
