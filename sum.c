#include <stdio.h>

void soma() {
	int soma = 0, i;
	
	for(i = 1; i < 1000; i++) {
		if(i % 3 == 0 || i % 5 == 0) {
			soma += i;
		}
	}
	
	printf("%d\n", soma);
}

int main() {
	
	soma();
	
	return 0;
}
