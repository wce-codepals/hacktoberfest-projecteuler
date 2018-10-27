#include<stdio.h>
void main()
{
int n,count,p,i;
for(n=2;n<500000;n++)
 {
count=0;
for(i=2;i<n;i++)
  {
    if(n%i==0)
    count++;
  }
  if(count==0)
   p++;
  if(p==10001)
  {
  printf("%d",n);
  break;
  }
 }
}
