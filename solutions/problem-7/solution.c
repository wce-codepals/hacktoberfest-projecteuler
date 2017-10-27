#include<stdio.h>
main()
{
    long i,j;
    int k=0,l=0;
    for(i=2;;i++)
    {
        for(j=2;j<=i;j++)
        {
            if(i%j==0)
            k++;
        }
        if(k==1)
        {
            l++;
        }
        k=0;
        if(l==10001)
            break;
    }
    printf("%d",i);
}
