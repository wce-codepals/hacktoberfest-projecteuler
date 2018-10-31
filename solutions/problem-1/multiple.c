#include<stdio.h>
void main()
{
int num;
printf("Enter a num");
scanf("%d",&num);
if(num%3==0 && num%5==0)
{
printf("Number is multiple of 3 and 5);
}
else
printf("not a multiple of 3 and 5");
}
