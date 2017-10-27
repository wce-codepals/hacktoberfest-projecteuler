//Add CPP solution to problem-6
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int sum_of_squares,square_of_sum,n=10,difference;
    sum_of_squares=n*(n+1)*(2*n+1)/6;
    square_of_sum=pow(n*(n+1)/2,2);
    difference=sum_of_squares-square_of_sum;
    cout<<"Difference between sum of square and square of sum is "<<difference<<endl;
    return 0;
}
