#include <stdio.h>

int main()
{
	int max=2, count=0, max_count=1;
	for(int i=2; i<1000000; i++)
	{
		while(i != 1)
		{
			if (i%2 == 0)
			{
				i = i / 2;
				count++;
			}
			else
			{
				i = 3i + 1;
				count++;
			}
		}
		if (count > max_count)
		{
			max_count = count;
			max = i;
		}
	}
	printf("Starting number : %d", max);
}
			
