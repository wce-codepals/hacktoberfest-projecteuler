#include<stdio.h>
#include<math.h>
int main()
  {
    int i,j,div,c,count=0,x;
    i=2;
    while(count!=9999)
       {
         for(j=2;j<=i/2;j++)
           {   
             c=0;
             div=i%j;
             if(div==0)
             {   
                c++;
                break;
             }
           }
         if(c==0)
            {
              count++;
              x=i;
            }
         i++;
        }
      printf("10001st prime number is %d.\n",x);
      return 0;
  }
