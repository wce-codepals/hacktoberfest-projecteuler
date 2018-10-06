#include <stdio.h>

int main()
{
	int num, flag=0;
	for (int i=1; i<1000000000000; i++)
	{
		for (int j=1; j<=20; j++)
		{
			if (i%j == 0)
			{
				num = i;
				flag=1;
			}
			else
			{
				flag=0;
				break;
			}
		}
		if (flag == 1)
		{
			goto label;
		}
	}
	label:
		printf("%d\n", num);
	return 0;
}
		
