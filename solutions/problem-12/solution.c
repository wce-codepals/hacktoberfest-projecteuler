#include <stdio.h>
#include <math.h>

int divisors(long long int n){
	long long int i = 2, d = 1;

	while(i <= sqrt(n)){
		if(n % i == 0){
			++d;
			if(i != n / i) ++d;
		}
		++i;		
	}

	return d;
}

long long int triangle(long long int n){
	int sum = 0;

	for(long long int i = 1; i <= n; ++i) sum += i;

	return sum;
}

int main(){
	long long int i = 2, t = 1;
	int d = 0;

	while(1){
		d = divisors(t);
		if(d >= 501) break;
		t = triangle(i);
		++i;
	}

	printf("%lld\t%d\n", t, d);
	return 0;
}
