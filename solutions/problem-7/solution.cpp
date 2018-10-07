/*
  Finding the 10001st prime number.
 */
#include <bits/stdc++.h>
using namespace std;
//Function that returns whether a number is prime or not.
int prime(int n)
{
	int c=0;
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
			c++;
	}
	if(c==0)
		return 1; //num is prime
	else
		return 0; //num is composite
}
int main()
{
	int count_prime=0, num=1;
	/*
	 * count_prime: stores the index of the prime number
	 * num: stores the natural numbers and is incremented in each iteration
	 */
	while(count_prime!=10001)
	{
		num++;
		if(prime(num)==1)
			count_prime++;
	}
	//Printing the number that is the 10001st prime number.
	cout<<num<<endl;
	return 0;
}
