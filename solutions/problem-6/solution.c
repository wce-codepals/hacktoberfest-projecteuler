#include<stdio.h>
void main(){
	int i=100, sumOfSq=0, sqOfSum=0;
	for(i=1;i<=100;i++){
		sumOfSq+=i*i;
		sqOfSum+=i;
	}
	sqOfSum=sqOfSum*sqOfSum;
	printf("%d\n",sqOfSum-sumOfSq);
}
