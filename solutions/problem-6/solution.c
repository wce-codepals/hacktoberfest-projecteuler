#include<stdio.h>
#define N 100

int main() {

	int i;
	long long int sum = 0,sumSquare = 0;
	for(i=1; i<=N; i++) {
		sum += i;
		sumSquare += i*i;
	}
	sum *= sum;
	printf("%lld\n", sum-sumSquare);
	return 0;
}