/* 
The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?
*/
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

vector<long long> v;

int main() {
	long long n = 600851475143;
	vector<long long> v;
	for(long long i = 3; i < sqrt(n); i++) {
		while (n%i == 0) {
	        v.push_back(i);
	        n = n/i;
		}
	}
	if (n>2) 
		v.push_back(n);
	long long size = v.size();
	sort(v.begin(), v.end());
	cout << v.at(size-1);
}
