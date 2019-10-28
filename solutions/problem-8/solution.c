#include <stdio.h>

int main()
{
	int a[1000];
	int largestprod = 1;
	int prod = 1;
	printf("Enter all the digits of the number seperated by spaces\n");
	for (int i = 0;i< 10; i++)
	{
		scanf("%d", &a[i]);
		if (i > 3)
		{
			prod = a[i] * a[i - 1] * a[i - 2] * a[i - 3];
		}
		else
		{
			prod = prod * a[i];
			largestprod = prod;
		}
		

		if (prod > largestprod)
		{
			largestprod = prod;
		}
	}
	printf("%d",largestprod);
	return 0;
}