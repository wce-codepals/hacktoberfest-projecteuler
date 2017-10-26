#include<stdio.h>

int main(){
	
	int i,contPrime = 0, cont = 0, j;

	for(i = 1; ; i++){

		for(j = 1; j <= i; j++)
			if(i % j == 0)
				cont++;

		if(cont == 2){
			cont = 0;
			contPrime++;
			if(contPrime == 10001){
				printf("%d\n", i);
				break;
			}
		}else
			cont = 0;	
	}

	return 0;
}
