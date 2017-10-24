#include <iostream>
using namespace std;

#define limit 20

bool isPrime(int ele) {
	
	bool flag = true;
	
	for (int i = 2; i < ele; ++i) {
		if(ele % i == 0) {	// divisible
			flag = false;
			break;
		}
	}
	return flag;
}

int main() {
	
	long sum = 0;
	
	for (long i = 2; i < limit; ++i) {
		if(isPrime(i)) {
			sum += i;
		}
	}
	
	cout << sum;

	return 0;
}
