#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
   	double t,a,b,c,n;
    long long max;
    long long x;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++)
    {
        double n;
        cin >> n;
        max=-1;
        for(a=1;a<n;a++)
        {
            b=(n*n-2*n*a)/(2*n-2*a);
            x=b;
            if(x==b)
            {    
            c=n-a-b;
            if(c>b&&b>a&&a*b*c>max)
                        max=a*b*c;
            }
        }
        cout<<max<<endl;
    }
    return 0;
}

