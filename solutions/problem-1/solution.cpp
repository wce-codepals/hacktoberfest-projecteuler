#include <bits/stdc++.g>
using namespace std;


int main() 
{
	
	long int t,i,o;
	long long n,s,a,m,p;
	cin>>t;

	while(t--)
	{

		cin>>n;
		s=0;i=3;o=2;
		
		while(o--)
		{ 

			m=n;
			while(m--)
			{
				if(m%i==0)
				{ 
					p=m;
					break; 
				}
			}   
			a=((p-i)/i)+1;
			s+=(a*(i+p))/2;
			i=5;         
		}  

		m=n;
		while(m--)
		{
			if(m%15==0)
			{
				p=m;
				break; 
			}
		}

		a=((p-15)/15)+1;
		s-=(a*(15+p))/2;         
		cout<<s<<"\n";            
	}
	return 0;
}
