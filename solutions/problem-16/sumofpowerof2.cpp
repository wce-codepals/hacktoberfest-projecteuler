#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t,i=0,n,sum;
    long p;
    cout<<"\nEnter no. of test cases: ";
    cin>>t;
    while(i<t)
    {
        cout<<"\nEnter power : ";
        cin>>n;
        p=pow(2,n);
        sum=0;
        while(p)
        {
            sum+=p%10;
            p/=10;
        }
        cout<<"\nSum= "<<sum;
        i++;
    }

    return 0;
}
