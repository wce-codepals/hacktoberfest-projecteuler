#include<stdio.h>


int isPrime(int n) 
{ 
    if (n <= 1)  return 0; 
    if (n <= 3)  return 1; 
  

    if (n%2 == 0 || n%3 == 0) return 0; 
  
    for (int i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return 0; 
  
    return 1; 
}

int retprime(int L)
{
	int c = 2;
	int n = 0;

	while (c < L) {

	n+= 6;

	if (isPrime(n + 1)==1) {
	  c++;
	}

	if (isPrime(n - 1)==1) {
	  c++;
	}
	}
	return n + 1;
}

void main()
{
	printf("%d\n", retprime(10001));
}
