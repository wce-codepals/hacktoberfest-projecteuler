/* Problem 6 : This program Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum. */
#include<stdio.h>


void main()
{
int i,sqr1,j=0,k=0,sqr2,diff;

//This loop find the sum of the squares of the numbers
for(i=1;i<101;i++){
sqr1=i*i;
j=j+sqr1;
}


//This loop find the square of sum of the numbers
for(i=1;i<101;i++){
k=k+i;
}
sqr2=(k*k);


//Here the difference is found
diff=sqr2-sqr1;
printf("The difference is: %d",diff);
}
