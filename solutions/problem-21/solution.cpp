#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long long t,n,i,j,k,sum;
    long long a[100001]={0};
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
        a[i]=sum;
        //cout<<a[i]<<endl;
    }
    a[0]=-1;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        sum=0;
        for(j=1;j<n;j++)
        {
          if(j<100001&&a[j]<100001&&j==a[a[j]]&&j!=a[j])
            sum+=j;
        }
        cout<<sum<<endl;
    }
    return 0;
}
