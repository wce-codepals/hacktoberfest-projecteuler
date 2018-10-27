#include<stdio.h>
void main()
{
int i,count=0,num;
unsigned int n=21;
while(count!=1)
{
n++;
for(i=1;i<=20;i++)
{
if(n%i==0)
num++;
else
num=0;
}
if(num==20)
{
count=1;
}
}
printf("\n %d",n);
}
