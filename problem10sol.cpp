#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
int count;
long sum=0;
for(long i=1;i<=2000000;i++)
{
    count=0;
    for(long j=1;j<=i;j++)
    {
        if(i%j==0)
        count++;
    }
    if(count==2)
        sum=sum+i;
}
cout<<"SUM IS:"<<sum;
}
