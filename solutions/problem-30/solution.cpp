#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    double n,i,j,k,sum,tot=0;
    cin>>n;
    for(i=10;i<600000;i++)
    {
        j=i;
        sum=0;
        while(j)
        {
            k=fmod(j,10);
            sum+=pow(k,n);
            j=floor(j/10);
        }
        if(sum==i)
            tot+=i;
    }
    cout<<(long long)tot;
    return 0;
}

