#include<stdio.h>
void main(){
	long num=600851475143, B=2, C;
	while(num!=1){
		if(num%B==0)
			num=num/B;
		else
			B++;
	}
	printf("%ld\n",B);
}
