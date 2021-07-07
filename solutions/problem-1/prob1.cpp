#include <iostream>
using namespace std;
int main()
{
    long long ans = 0;
    for(int i = 1; i < 1000; i++)
    {
        if(i%3==0)
            ans+=i;
        if(i%5==0)
            ans+=i;
        if(i%15==0)
            ans-=i;
    }
    cout<<ans<<endl;

}