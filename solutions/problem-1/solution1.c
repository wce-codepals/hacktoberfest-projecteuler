#include <stdio.h>


int main()
{

  int c=0;
  for(int i=0;i<1000;i++)
   {
      if(i%3==0||i%5==0)
        c=c+i; 
   }

  printf("%d\n",c);


 return 0;
}
