#include <stdio.h>
#include <math.h>
int main()
{
	int i, j, k, tempi, tempj, tempk;
	for (i=1; i<1000; i++)
	{
		for (j=1; j<1000; j++)
		{
			for (k=1; k<1000; k++)
			{
				if ((pow(i,2) + pow(j,2)) == (pow(k,2)))
				{
				       if (i+j+k == 1000)
				       {
					       tempi=i;
					       tempj=j;
					       tempk=k;
					       goto label;
				       }
				}
			}
		}
	}
	label:
		printf("Special Pythagorean Triplet = %d %d %d", i, j, k);
	return 0;
}	
