#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long long t,n,i,j,k,sum;
    long long a[100001]={0};
    long long b[100001]={0};
    k=0;
    for(i=1;i<100001;i++)
    {
        sum=0;
        for(j=1;j*j<=i;j++)
        {
            if(i%j==0)
            {
                if(j!=i)
                    sum+=j;
                if(i/j!=j&&i/j!=i)
                    sum+=i/j;
            }
        }
        if(sum>i)
        {b[k++]=i;a[i]=1;}
    }
    a[0]=-1;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        int flg=0;
        for(j=0;j<k&&b[j]<n;j++)
        {
            if(a[n-b[j]]==1)    
            {
                flg=1;break;    
            }
        }
        if(flg)
           cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }   
    return 0;
}

