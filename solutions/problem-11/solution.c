#include <stdio.h>

int main() 
{
    int i,j;
    long long int max=0;
    int A[20][20];
    for(i=0;i<20;i++)
    {
        for(j=0;j<20;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    for(i=0;i<20;i++)
    {
        long long int h=1,v=1,d=1,dd=1;
        for(j=0;j<20;j++)
        {
            if( (i+3) < 20 )
            {
                v=A[i][j]*A[i+1][j]*A[i+2][j]*A[i+3][j];
            }
            if( (j+3) < 20 )
            {
                h=A[i][j]*A[i][j+1]*A[i][j+2]*A[i][j+3];
            }
            if( ( (i+3) < 20 ) && ( (j+3) < 20) )
            {
                d=A[i][j]*A[i+1][j+1]*A[i+2][j+2]*A[i+3][j+3];            
            }
            if( i > 2 && j<17 )
            {
                dd=A[i][j]*A[i-1][j+1]*A[i-2][j+2]*A[i-3][j+3];
            }
            if(v>max)
            {
                max=v;
            }
            if(h>max)
            {
               max=h;
            }
            if(d>max)
            {
                max=d;
            }
            if(dd>max)
            {
                max=dd;
            }
        }  
    }
    printf("%lld",max);
    return 0;
}
