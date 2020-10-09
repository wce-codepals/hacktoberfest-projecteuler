//Add CPP solution to problem-5
// It calculates the LCM of first n natural numbers using prime factorization method
#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>

using namespace std;

bool isprime(int x) // checks if x is prime
{
    for(int i = 2; i * i <= x; i++)
        if(x % i == 0)
            return false ;
    return true ;
}

vector<int> prime_factors(int x) // returns the vector containing prime factors of x
{
    int j = 2;
    vector<int> factors;
    while(j <= x)
    {
        if(isprime(j) && (x % j) == 0)
        {  
            factors.push_back(j);
            x /= j;
        }
        else j++;
    }
    return factors;
}
int main()
{
    int n = 20;
    vector<pair<int,int>> primes;
    for(int i = 2; i <= n; i++)
        if(isprime(i))
            primes.push_back({i,0});
    
    vector<vector<int>> num(n+1); // contains ith integer and it's prime factorization
    for(int i = 2; i <= n; i++)
    {
        num[i] = prime_factors(i);
    }
    long long int ans = 1;
    for(auto p : primes)
    {
        for(int i = 2; i <= n; i++)
        {
            int c = count(num[i].begin(), num[i].end(), p.first) ;
            p.second = max(c , p.second) ;
        }
        ans *= pow(p.first,p.second);
    }
    cout << ans <<endl;
    return 0;
}