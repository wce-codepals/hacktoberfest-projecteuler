#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int q=0,n,i,j,k=0;
    scanf("%d",&n);
    char a[n][50],t[53],tmp;
    for(i=0;i<n;i++)
        {
        scanf("%s",a[i]);
        }
     for(j=49;j>=0;j--)
         {
         for(i=0;i<n;i++)
             {
             q+=a[i][j]-48;
              }
         t[k]=(q%10)+48;
         k++;q/=10;
         }
    for(j=k;j<53;j++)
        {
        t[j]=(q%10)+48;
        q/=10;
        }
    i=0;j=52;
    while(i<=j)
        {
        tmp=t[i];
        t[i]=t[j];
        t[j]=tmp;
        i++;j--;
        }
    for(i=0;i<53;i++)
        {
        if(t[i]!='0')
        {j=i;break;}
        }
    for(k=j;k<j+10;k++)
    printf("%c",t[k]);
    return 0;
}
