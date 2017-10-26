//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cctype>
#include <climits>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#define SZ(x) (int)((x).size())
#define PII pair<int,int>
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long LL;
bool is_prime ( int x ) {
	int y=sqrt(x);
	for ( int i=2; i<=y; i++ ) 
		if ( x%i==0 ) return 0;
	return 1;
}
int main ()
{
	for ( int i=2,cnt=0; ; i++ ) {
		if ( is_prime(i) ) cnt++;
		if ( cnt==10001 ) {
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}

