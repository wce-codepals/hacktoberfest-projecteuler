#include<stdio.h>
void main()
{
int num,count1,primeno,i;
for(num=2;num<500000;num++)
{
count1=0;
  for(i=2;i<num;i++)
  {
    if(num%i==0)
    count1++;
   }
   if(count1==0)
   primeno++;
   if(primeno==10001)
   {
   printf("%d\n",num);
   break;
   }
  }
}
