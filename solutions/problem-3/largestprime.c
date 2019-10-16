#include <math.h> 
#include <stdio.h> 
long long maxPrimeFactors(long long n) 
{ 
    
    long long maxPrime = -1; 
  
     
    while (n % 2 == 0) { 
        maxPrime = 2; 
        n >>= 1;  
    } 
  

    for (int i = 3; i <= sqrt(n); i += 2) { 
        while (n % i == 0) { 
            maxPrime = i; 
            n = n / i; 
        } 
    } 
    if (n > 2) 
        maxPrime = n; 
  
    return maxPrime; 
} 
  
int main() 
{ 
    int t,i=0;
    printf("\nEnter no. of test cases:");
    scanf("%d",&t);
    int n; 
    while(i<t)
    {
        printf("\nEnter a number: ");
        scanf("%d",&n);
        printf("\nmaximum prime factor:%lld\n", maxPrimeFactors(n));
        i++;
    }
  
    return 0; 
} 
