/*
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

a2 + b2 = c2
For example, 32 + 42 = 9 + 16 = 25 = 52.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 1000, ma = -1, k;
    for(int i = 1; i <= n/2; i++) {
        for(int j = (n - i)/2;j < i && j < n - i;j++) {
            k = n - i - j;
            if(k > j)
                continue;
            if(j*j + k*k == i*i)
                if(i*j*k > ma)
                    ma = i*j*k;
        }
    }
    cout<<ma<<endl;
	return 0;
}
