#include<stdio.h>
void main()
{ int i,sum=0;
for(i=1;i<=1000;i++)
{
if(i%3==0||i%5==0)
sum=sum+i;
}
printf("\n The sum is: %d",sum);
}
