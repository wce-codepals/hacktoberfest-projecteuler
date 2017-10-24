/Add C solution to problem-5
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    int arr[20];
    int i, j, k;
    int smallNum = 1;
    for (i = 1; i <= 20; i++)
       arr[i] = i;
    
    for (i = 2; i <= 20; i++)
    {
        for (j = 2; j <= arr[i]; j++)
        {
            while (arr[i] % j == 0)
            {
                smallNum = smallNum * j;
                for (k = i; k <= 20; k++)
                {
                    if (arr[k] % j == 0)
                        arr[k] = arr[k] / j; 
                }
            }
        }
    } 
    printf("%d\n",smallNum);
       
}
