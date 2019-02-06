/*
 Finding the sum of the terms in the Fibonacci series that are even valued.

 Terms should be <= 4,000,000
 Given, first term of series = 1, second term of series = 2
 
 In the Fibonacci series, new term = sum of previous two terms
 Hence, in the above case, the new term = first term + second term
 i.e., new term = 1 + 2 = 3

 I have used a vector in which the even terms are pushed and 
 then calculated the sum of the vector elements.
 */

#include <bits/stdc++.h>
using namespace std;
//function that returns whether a number is even or odd
int even(int n)
{
	if(n%2==0)
		return 1;
	else return 0;
}
int main()
{
	/*
	 a: first term
	 b: second term
	 term: new term
	 sum: sum of the even valued Fibinacci series terms 
	 */
	int a=1, b=2, term=0, sum=2;
	vector <int> v;
	//Vector storing integer values dynamically
	//Pushing 2 to the vector for the first case, initializing sum to 2
	v.push_back(2);
	while(term<=4000000)
	{
		if(term!=0 && even(term)==1)//
		{
			v.push_back(term);
			sum+=term;
		}
		//Swapping values: new 'a' is old 'b', new 'b' is old 'a+b'
		term = a + b;
		a = b;
		b = term;
	}
	//Printing the sum
	cout<<endl<<sum;
	return 0;
}
