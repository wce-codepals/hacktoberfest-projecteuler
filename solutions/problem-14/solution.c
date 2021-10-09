#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
long long a[5000001];
int main() 
{
    long long t,i,j,n,cnt,mcnt=1,k,ans;
    for(i=1;i<5000001;i++)
    {
        cnt=0;
        k=i;
            while(k!=1)
            {
                if(k%2)
                    k=3*k+1;
                else
                    k=k/2;
              cnt++;
            }
        if(i==1)
           a[i]=1;
        else
        {
            if(cnt>=mcnt)
            {
                mcnt=cnt;
                a[i]=i;
            }
            else
            {
                a[i]=a[i-1];
            }
        }
    }
    scanf("%Ld",&t);
    for(i=0;i<t;i++)
    {
        scanf("%Ld",&n);  
        printf("%Ld\n",a[n]);
    }
    return 0;
}

