#include<iostream>
using namespace std;
int main()
{
long sum=0,squaresum=0;
for(int i=1;i<=100;i++)
{
sum=sum+i;
squaresum=squaresum+i*i;
}
cout<<"Diference is:";
cout<<sum*sum-squaresum;
return 0;
}
