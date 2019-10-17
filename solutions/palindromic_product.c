#include<stdio.h>
#include<math.h>

int main()
  {
    int i,j;
    long int max_product=0, product;
    int upper_limit=999, lower_limit=100;
    
    for(i=upper_limit; i>=lower_limit; i--)
        {
          for(j=i; j>=lower_limit; j--)
              {
                product=i*j;
                if(product<max_product)
                   break;
                int num=product;
                int rev=0;
                
                while(num!=0)
                   {
                      rev=(rev*10) + (num%10);
                      num=num/10;
                   }
                
                if(rev==product && product>=max_product)
                    max_product=product;
                    
               }
        }
   printf("The largest palindromic product of two 3-digit numbers is %ld.\n",max_product);
   return 0;
 }
               
