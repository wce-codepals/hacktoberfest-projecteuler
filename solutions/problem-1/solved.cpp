#include<iostream>

using namespace std ;

int main()
{
    int a[10000] , s = 0;
    for (int i = 0; i < 1000 ; i++)
    {
	if ( i % 3 == 0 || i % 5 == 0)
	    a[i] = i ;
    }
    
    for (int i = 0; i < 1000 ; i++)
	{
	    s += a[i] ;	
	}
	cout << s;
    return 0;
}
