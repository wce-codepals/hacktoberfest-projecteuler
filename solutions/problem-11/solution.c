#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    long long i,j,k;
    double s1,s2,s3,s4,max=0;
    long long a[20][20];
    for(i=0;i<20;i++)
        for(j=0;j<20;j++)
        scanf("%Ld",&a[i][j]);
        for(i=0;i<20;i++)
        {
        for(j=0;j<20;j++)
            {
            k=0;
            s1=s2=s3=s4=1;
                while(1)
                    {
                        if(i+k<20)
                            s1*=a[i+k][j];
                        if(j+k<20)
                            s2*=a[i][j+k]; 
                        if(i+k<20&&j+k<20)
                            s3*=a[i+k][j+k];
                        if(i-k>=0&&j+k<20)
                               s4*=a[i-k][j+k];
                    k++;
                    if(k==4)
                        break;
                    }
           // printf("%lf %lf %lf %lf\n",s1,s2,s3,s4);
            if(s1>max)
                max=s1;
            if(s2>max)
                max=s2;
            if(s3>max)
                max=s3;
            if(s4>max)
                max=s4;
            }
        }
    printf("%.0lf",max);

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}

