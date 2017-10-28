//Add CPP solution to problem-3

/*
 *
 * The prime factors of 13195 are 5, 7, 13 and 29.
 * What is the largest prime factor of the number 600851475143 ?
 *
 */

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll n = 600851475143L;
    for(ll i = 2; i*i < n; i++) {
        while(n%i == 0)
            n /= i;
    }
    cout<<n<<endl;
	return 0;
}
