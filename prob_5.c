#include<stdio.h>
void main()
{
  int num,i,count;
  
 for(num=20;num<10000000000;num++)
 { count=0;
  for(i=1;i<=20;i++)
  {
   if(num%i==0)
   count++;
   }
   if(count==20)
   { printf("%d",num)
     break;
   }
}
 
