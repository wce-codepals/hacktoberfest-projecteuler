#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n) 
{ 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
  

    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (int i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
  
    return true; 
}

int retprime(int L)
{
	int c = 2;
	int n = 0;

	while (c < L) {

	n+= 6;

	if (isPrime(n + 1)) {
	  c++;
	}

	if (isPrime(n - 1)) {
	  c++;
	}
	}
	return n + 1;
}

int main()
{
	cout<<retprime(10001)<<endl;
	return 0;
}
