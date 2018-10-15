#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll t,n,sum = 0;
    cin>>t;
    while(t--){
        cin>>n;
        sum = 0;
        ll no3 = (n%3 == 0) ? (n/3 - 1) : (n/3);
        ll no5 = (n%5 == 0) ? (n/5 - 1) : (n/5);
        ll no15 = (n%15 == 0) ? (n/15 - 1) : (n/15);
        
        ll sum3 = 3*no3*(1+no3)/2;
        ll sum5 = 5*no5*(1+no5)/2;
        ll sum15 = 15*no15*(1+no15)/2;
        sum = sum3 + sum5 - sum15;
        cout<<sum<<endl;
    }
    return 0;
}
