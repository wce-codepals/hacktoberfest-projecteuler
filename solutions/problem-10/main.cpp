#include <iostream>

using namespace std;
bool checkprime(int64_t n)
{
    int64_t k=2;
    for(k=2;k*k<=n;k++)
    {
        if(n%k==0)
            return false;
    }
    return true;
}
int main()
{
    int64_t x=2000000;

    int64_t sum=0;
    for(x=2;x<2000000;x++)
        {
            if(checkprime(x))
            {   //cout<<x<<endl;
                sum+=x;
            }
        }
        cout<<sum;

    return 0;
}
