#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll t,n;
    cin>>t;
    while(t--){
        cin>>n;
        ll sum1 = n*(n+1)/2;
        sum1 *= sum1;
        
        ll sum2 = n*(n+1)*(2*n+1)/6;
        cout<<abs(sum1-sum2)<<endl;
    }
    return 0;
}
