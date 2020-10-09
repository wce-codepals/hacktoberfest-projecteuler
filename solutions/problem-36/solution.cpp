#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool is_planidrome(const string & s) {
	int i = 0, j = s.length() - 1;
	while (i < j) {
		if (s[i] != s[j])
			return false;
		i++;
		j--;
	} 
	return true;
}

string to_bool_string(int n) {		//converts int to boolean string
	string s;
	while (n) {
		if (n & 1)
			s.push_back('1');
		else s.push_back('0');
		n/=2;
	}
	reverse(s.begin(), s.end());
	return s;
}

int main() {
	int n = 1e6;  	// calculting upto 1 million
	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		if (is_planidrome(to_string(i)) && is_planidrome(to_bool_string(i)))
			sum+=i;
	}
	cout<<sum<<endl;
}