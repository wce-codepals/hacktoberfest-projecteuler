#include <bits/stdc++.h>
#define ll long long int 
using namespace std;

int main() {
    ll t,n;
    cin>>t;
    while(t--){
        cin>>n;
        ll ans = 1;
        for(ll i=2;i<=n;i++){
            if(__gcd(i,ans) == 1) ans *= i;
            else ans = i*ans/__gcd(i,ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}
