#include <bits/stdc++.h>
using namespace std;
int main()
{
  int i,sum=0;
  for(i=1;i<1000;i++)
  {
    if(i%3==0 || i%5==0)
    {
      sum=sum+i;
    }
  }
  cout<<sum<<"\n";
}
