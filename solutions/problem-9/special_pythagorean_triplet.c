#include<stdio.h>
#include<math.h>

int main()
  {
    long int a,b,c,product;
    for(a=0;a<1000;a++)
       {
         for(b=a+1;b<1000;b++)
            {
              for(c=b+1;c<1000;c++)
                 {
                    if((a*a)+(b*b)==(c*c) && a+b+c==1000)
                       {
                         product=a*b*c;
                       }
                  }
             }
        }
     printf("The product of Pythagorean triplet is %ld.\n",product);
  }
