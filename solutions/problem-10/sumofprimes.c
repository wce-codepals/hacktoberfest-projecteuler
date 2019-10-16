#include<stdio.h>

int main(){

    int i,k,f,n,sum=0;

    printf("Enter range for sum of prime numbers : ");
    scanf("%d",&n);
    
    for(i= 2; i<= n; i++)

   {

    f=0;

    for(k=2; k<=i/2; k++)

   {

        if((i % k) == 0){

        f++;

        break;

        }

    }

   if(f==0)

   sum += i;

   }

   printf("\n   Sum of prime numbers is:  %d ",sum);

   return 0;

}
