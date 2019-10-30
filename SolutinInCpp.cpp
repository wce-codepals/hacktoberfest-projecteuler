#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main() 
{
    long long i,j,t,n,k,sum;
    long long a[1000001],b[1000001];
    a[1]=0;
    k=0;
    for(i=2;i<1000001;i++)
    {
        a[i]=1;
    }
    for(i=2;i<1000001;i++)
    {
        if(a[i]!=0)
        {
            for(j=1;j*i<1000001;j++)
            {
                a[j*i]=0;    
            }
            b[k++]=i;
        }
        if(k==1000001)    break;
    }
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        sum=0;
        for(j=0;j<1000001;j++)
         {
            if(b[j]>n)  break;
            sum+=b[j];
        }
        cout<<sum<<endl;
    }
    return 0;
}
