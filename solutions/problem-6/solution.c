#include <stdio.h>

int main()
{
    int i,T;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        unsigned long long int N,sum1=0,sum=0,sum2=0,total=0;
        scanf("%llu",&N);
        sum1=(N*(N+1)*((2*N)+1))/6;
        sum=(N*(N+1))/2;
        sum2=sum*sum;
        total=sum2-sum1;
        printf("%llu\n",total);
    }
    return 0;
}
