#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
    long long i,j,t,n,k,s,cnt;
    n=500000;
    long long a[n+1],b[100001];
    a[1]=0;
    k=0;
    for(i=2;i<n+1;i++)
    {
        a[i]=1;
    }
    for(i=2;i<n+1;i++)
    {
        if(a[i]!=0)
        {
            for(j=1;j*i<n+1;j++)
            {
                a[j*i]=0;    
            }
            b[k++]=i;
        }
        if(k==100001)    break;
    }
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        cnt=0;
        for(j=0;b[j]<=n&&j<100001;j++)
        {
            s=n-b[j];
            k=sqrt(s/2.0);
            if((s/2.0)==k*k)
                cnt++;
        }
        
     cout<<cnt<<endl;
    }
    return 0;
}
