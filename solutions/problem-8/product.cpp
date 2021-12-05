#include <iostream>

#include <string>
#include <cmath>

using namespace std;
int main() 
{
	int i,t,n,k,j,l;
	char s[1001];
	long long p,max;
	cin>>t;
	for(i=0;i<t;i++) 
	{
		max=0;
		cout<<"\nEnter no. of digits:  ";
		cin>>n;
		cout<<"\nEnter no.of consecutive digits: ";
		cin>>k;
		cout<<"\nEnter number";
		cin.getline(s,1001); 
		
	 	for(j=0;j<=n-k;j++)
	      	{
	     		p=1;
		     	for(l=j;l<j+k;l++)
			{
		 		p*=(long long)(s[l]-48);
	     		}
	     		if(p>max)
		 		max=p;
	 	}
            	cout<<max<<"\n";
        }
    return 0;
}
