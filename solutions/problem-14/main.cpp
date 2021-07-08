#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
vector<int64_t> dp(1000001);

int64_t collatz(int64_t n)
{

    if(n==0)
        return 0;
    if(n==1)
        return 1;

    if(n<=1000000)
    {if(dp[n]!=-1)
        return dp[n];}

    if(n%2==0)
    {   if(n<=1000000)
        {dp[n]=1+collatz(n/2);
        return dp[n];}
        else
        {
            return 1+collatz(n/2);
        }
    }
    else
    {   if(n<=1000000)
        {dp[n]=1+collatz(3*n+1);
        return dp[n];}
        else
        {
            return 1+collatz(3*n+1);
        }
    }
}

int main()
{
int64_t x;
for(x=0;x<=1000000;x++)
{  dp[x]=-1;
}
dp[0]=0;
dp[1]=1;
int64_t maximum=-1;
int answer;

for(x=1;x<=1000000;x++)
{
    if(collatz(x)>maximum)
        {maximum=collatz(x);
        answer=x;}

}
cout<<answer;

return 0;
}
