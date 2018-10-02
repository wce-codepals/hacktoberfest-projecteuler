#include <stdio.h>
#define MAX 100

int main(){
	int sum=0, i, t=0;
	for(i=1; i<=MAX; i++){
		sum+=i*i;
		t+=i;
	}
	printf("%d\n", -sum+t*t);
	return 0;
}
