#include<stdio.h>
int main()
{
int i,r,sum=0;
double c=1;
for(i=1;i<=1000;i++)
{
c=c*i;}
printf("Value of  the factorial is %f",c);
while(c!=0)
{
r=(int)c%10;
sum=sum+r;
c=c/10;
}
printf("The sum of the digits is %d",sum);
return 0;
}