#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
     long sum=0;
    int j,sum1=0;
     long i;
    int k=0;

    for(i=2;i<999999;i++)
    {   sum1=0;
        k=i;
        for(;k!=0;)
        {  j=k%10;
            j=pow(j,5);
            k=k/10;
            sum1=j+sum1;
        }

        if(sum1==i)
        {
            sum=sum+i;

        }
    }
    printf("%ld",sum);
    return 0;
}
