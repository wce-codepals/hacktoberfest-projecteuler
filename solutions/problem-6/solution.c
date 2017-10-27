#include<stdio.h>
#include<math.h>
void main()
{
    int sum_of_squares,square_of_sum,n=10,difference;
    sum_of_squares=n*(n+1)*(2*n+1)/6;
    square_of_sum=pow(n*(n+1)/2,2);
    difference=sum_of_squares-square_of_sum;
    printf("Difference between sum of square and square of sum is %d",difference);
}
