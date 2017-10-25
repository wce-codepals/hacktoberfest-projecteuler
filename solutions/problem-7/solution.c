#include <stdio.h>
#define NUM 10001

int prime(unsigned long long int p){
	int boo = 1;
	unsigned long long i;
	for(i = p - 1; i > 0; --i){
		if(p % i == 0 && i != 1){
			boo = 0;
			return boo;
		}
	}
	return boo;
}

int main(){
	unsigned long long int i = 0, p = 1;
	
	while(i < NUM){
		++p;
		if(prime(p)) ++i;
	}
		
	printf("%lld - %lld\n", p, i);
	return 0;
}
