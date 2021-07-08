#include<iostream>
#include<limits.h>
using namespace std;

bool checkprime(int n)
{
    int k=2;
    for(k=2;k<n;k++)
    {
        if(n%k==0)
            return false;
    }
    return true;
}
int main()
{
    int count=0;
    int x=2;
    while(true)
    {
        if(checkprime(x))
        {
            count+=1;

        }
        if(count==10001)
            break;
        x+=1;
    }
cout<<x<<endl;
}
