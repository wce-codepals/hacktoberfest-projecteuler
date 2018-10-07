#include <math.h>
#include <stdio.h>

int main(){
    
    long a3,a5,a15;
    
        a3=0;a5=0,a15=0;
        scanf("%d",&n);
        a3=ceil((1000-1)/3);
        a5=ceil((1000-1)/5);
        a15=ceil((1000-1)/15);
        a3=(a3*(2*3+(a3-1)*3))/2;
        a5=(a5*(2*5+(a5-1)*5))/2;
        a15=(a15*(2*15+(a15-1)*15))/2;
        a3=a3+a5-a15;
        printf("%ld\n",a3);
    
    return 0;
}