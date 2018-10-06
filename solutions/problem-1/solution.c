#include <stdio.h>

int main()
{
  int  m1 = 0, m2 = 0, m3 = 0;
  for (int i = 0; i < 1000; i++) 
  {
    if (i % 3 == 0)	//Multiples of 3 
    {
      m1 += i;
    }
    if (i % 5 == 0)     //Multiples of 5
    {
      m2 += i;
    }
    if (i % 15 == 0)    //Multiples of 15
    {
      m3 += i;
    }
}
printf("%d\n", m1 + m2 - m3);
return 0;
}
