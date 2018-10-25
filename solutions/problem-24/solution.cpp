#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    string sout;
    long long t,n,m,i,j,k,s;
    cin>>t;
    long long fac[13];
    fac[0]=1;
    for(i=1;i<13;i++)
    {
        fac[i]=fac[i-1]*i;
    }
    for(i=0;i<t;i++)
        {
            sout="";
            int a[13]={0};
            cin>>n;
            n--;
            s=12;
            while(s>=0&&n)
            {
                    k=fac[s];
                    m=n/k;
                    n=n%k;   
                    long long cnt=-1;
                    for(j=0;j<13;j++)    
                    {
                        if(a[j]==0) 
                        {
                            cnt++;
                            if(cnt==m)
                            {
                                a[j]=1;
                                sout+=(char)(j+97);
                                break;
                            }
                        }
                    }
                    s--;
            }
            cout<<sout;
            for(j=0;j<13;j++)    
            {
                if(a[j]==0) cout<<(char)(j+97);
            }
            cout<<endl;
        }
    return 0;
}

