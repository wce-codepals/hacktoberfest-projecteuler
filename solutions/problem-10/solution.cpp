#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int A[20000000]={0};    //If array element at index 'i' is 0, then 'i' is prime, else 'i' is not prime
int main() {
	int i,j;
	long int s=0;
	set<int>S;    // set to store distinct prime numbers
	A[1]=1;
	A[0]=1;
	i=2;
	while(i<=2000000)    
	{
	    if(A[i]==0)
	    {
	        S.insert(i);   // If a number is prime, insert it into the stack
	    j=2;
	    while(i*j<=2000000)
	    {
	       A[i*j]=1;
	       j++;
	    }
	    }
	    i++;
	}
	auto it=S.begin();
	while(it!=S.end())
	{
	    s+=*(it);      // store sum of all prime numbers upto 2000000 in 's'
	    it++;
	}
	cout<<s<<endl;
	return 0;
}

//Answer 142913828922
