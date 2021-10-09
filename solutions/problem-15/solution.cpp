#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ModL=pow(10,9)+7;
int main() {
    ll t,i,j,k,n,m;
    n=501;
    ll a[n+1][n+1];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==0||j==0)  a[i][j]=1;
            else    a[i][j]=(a[i-1][j]+a[i][j-1])%ModL;
        }
    }
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>m;
        cout<<a[n][m]<<endl;
    }
    return 0;
}

