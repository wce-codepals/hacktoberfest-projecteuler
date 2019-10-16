#include <stdio.h>
#include<math.h>

int main()
{
    int t,i=0,n,sum;
    long p;
    printf("\nEnter no. of test cases: ");
    scanf("%d",&t);
    while(i<t)
    {
        printf("\nEnter power : ");
        scanf("%d",&n);
        p=pow(2,n);
        sum=0;
        while(p)
        {
            sum+=p%10;
            p/=10;
        }
        printf("\nSum:%d",sum);
        i++;
    }

    return 0;
}
