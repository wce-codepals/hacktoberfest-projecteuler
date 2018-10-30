#include<stdio.h>
void sort(int a[],int n)
{
int i,j;
for(i=0;i<n;i++)
{
for(j=0;j<n-i-1;i++)
{
if(a[i]>a[i+1])
{
int temp=a[i];
a[i]=a[i+1];
a[i+1]=temp;
}
}
}

}
int main()
{
return 0;
}
