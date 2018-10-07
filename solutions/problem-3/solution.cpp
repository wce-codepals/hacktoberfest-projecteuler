/*
 Finding the largest prime factor of 600851475143.
 */

#include<bits/stdc++.h>
using namespace std;
//function that returns whether a number is prime or not
long prime(int n)
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
	long num = 600851475143, big=0;
	/*
	 big: stores the largest prime number  
	 */
	for(long i=2;i<=sqrt(num);i++)
	{
		if(num%i==0 && prime(i)==1)
			big = i;
	}	
	//Printing the result
	cout<<big<<endl;
	return 0;
}
