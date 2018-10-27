#include<stdio.h>
void main()
{
int r,i,sum=0;
double a=1;
for(i=0;i<1000;i++)
{
a=a*2;
}
printf("Value of a is %G",a);
while(a!=0)
{
r=(int)a%10;
sum=sum+r;
a=a/10;
}
printf("The sum of the digits of that number is %d",sum);
}