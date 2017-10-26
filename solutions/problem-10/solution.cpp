//https://projecteuler.net/problem=10
#include <iostream>
using namespace std;
int const MAX = 2000000;

int checkPrime(int n){
    int range = n;
    for (int i = 2; i < range; i++){
        if (n%i == 0){
            return 0;
        }
        range = n / i;
    }
    return 1;
}

int main() {
	
	double sum = 0;
	for (int i = 2; i < MAX; i++){
		if (checkPrime(i) == 1){
	            	sum += i;
		}
	}
	cout<<sum;
	
	return 0;
}