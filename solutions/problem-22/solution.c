#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int cmpfunc(const void *a,const void *b)
    {
    return strcmp((char *)a,(char *)b);
}
int main() {
    int i,j,n,q,k;
    long long sum;
    scanf("%d",&n);
    char a[n][1000];
    char tmp[1000];
    for(i=0;i<n;i++)
        scanf("%s",a[i]);
    qsort(a,n,1000,cmpfunc);
    scanf("%d",&q);
    for(i=0;i<q;i++)
        {
        sum=0;
        scanf("%s",tmp);
        for(j=0;j<n;j++)
        {if(strcmp(a[j],tmp)==0)
            break;}
        for(k=0;a[j][k]!='\0';k++)
            {
            sum+=(long long)(a[j][k]-64);
        }
        printf("%Ld\n",sum*(j+1));
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}

