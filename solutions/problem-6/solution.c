#include<stdio.h>
#include<math.h>

int main(){
	
	int i;
	int first = 0, second = 0;

	for(i = 1; i <= 100; i++){
		first += pow(i, 2);
		second += i; 
	}

	second = pow(second, 2);

	int dif = second - first;
	printf("%d\n",dif);

	return 0;
}
