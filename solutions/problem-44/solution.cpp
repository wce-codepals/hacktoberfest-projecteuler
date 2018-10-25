#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> vec;
int main() 
{
    ll n,k,i,j;
    cin>>n>>k;
    for(i=1;i<n;i++)
    {
        j=(i*(3*i-1))/2;
        vec.push_back(j);
    }
    for(i=0;i<n-1;i++)
    {
        if(i-k>=0&&binary_search(vec.begin(),vec.end(),vec[i]-vec[i-k]))
            cout<<vec[i]<<endl;
        else if(i-k>=0&&binary_search(vec.begin(),vec.end(),vec[i]+vec[i-k]))
            cout<<vec[i]<<endl;
    }
    return 0;
}

