#include <stdio.h>

int main()
{
	unsigned long a = 1, b = 2, sum = 2, c = 0;
	while (c < 4000000)
	{
		c = a + b;
		if (c % 2 == 0)
			sum += c;

		a = b;
		b = c;
	}
	printf("Sum: %ld\n", sum);
	return 0;
}