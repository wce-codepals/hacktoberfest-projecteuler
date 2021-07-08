#include <iostream>

using namespace std;
int counter(int n)
{
    int k=1;
    int divisors=0;
    for(k=1;k*k<=n;k++)
    {
        if(n%k==0)
        {
            divisors+=1;
            if(n/k!=k)
            {
                divisors+=1;
            }
        }
    }
    return divisors;
}
int main()
{
   int z=1;

   while(true)
   {
       if(counter(((z)*(z+1))/2)>=500)
        break;
    z+=1;

   }
    cout<<(z*(z+1))/2;
    return 0;
}
