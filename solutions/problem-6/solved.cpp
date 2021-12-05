#include<iostream>

using namespace std;

int main()
{
    int a = 0 , b = 0 ;
    for (int i = 0; i <= 100; i++)
    {
	    a = a + (i*i);
	    b += i;
    }

   int d = (b*b)-a;
   cout << d;
  return 0;
}
