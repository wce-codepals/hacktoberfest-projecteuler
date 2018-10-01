/*
  *
  * Project Euler Problem 8 Solution (solution.cpp)
  * Author: Rishi Sharma
  * #HacktoberFest
  *
  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	long long maxAns = 0;
	for(int i=0; i<s.size(); ++i)
	{
		string s2 = s.substr(i, 13);
		long long ans=1;
		for(auto z: s2)
			ans*=(long long)(z-'0');
		if(maxAns<ans)
			maxAns=ans;

	}
	cout << maxAns << endl;
	return 0;
}
