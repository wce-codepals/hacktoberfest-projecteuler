#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
	int i,t,n,k,j,l;char s[1001];
	long long p,max;
	scanf("%d",&t);
    for(i=0;i<t;i++) 
    {
        max=0;
    scanf("%d %d %s",&n,&k,&s);
         for(j=0;j<=n-k;j++)
              {
             p=1;
             for(l=j;l<j+k;l++)
                 {
                 p*=(long long)(s[l]-48);
             }
             if(p>max)
                 max=p;
         }
            printf("%Ld\n",max);
        }
    return 0;
}

