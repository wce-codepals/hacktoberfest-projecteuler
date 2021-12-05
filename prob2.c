#include<stdio.h>
void main()
{
int a1=1;a2=2,a3,evensum=2;
while(a3<4000000)
{
a3=a1+a2;
if(a3%2==0&&a3<4000000)
evensum+=a3;
a1=a2;
a2=a3;
}
printf("%d\n",evensum);
}
