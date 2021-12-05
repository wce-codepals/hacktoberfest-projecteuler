#include<iostream>
using namespace std;
int main()
{
	int check,n=0,c=0;
	cout<<"enter the number:";
	cin>>n;
	for(int i=2;i<=100000000;i++)
	{
		check=0;
		for(int j=2;j<=i/2;j++)
		{
			if(i%j==0)
			{
				check=1;
				break;

			}
		}
		if(check==0)
			c++;
		if(c==n)
		{
			cout<<i;
	        break;
	    }
	}

return 0;
}
