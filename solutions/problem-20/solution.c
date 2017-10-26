#include <stdio.h>
#include <conio.h>
void main() {
    //declaration
    int n, fac;
    
    //input a number
    printf("enter a number");
    scanf("%d", &n);
    
    //calculate the factorial
    fac = 1;
    for (; n != 0; n--) {
        fac = fac * n;
    }
    
    //declaration
    int a[100], i = 0, sum = 0;
    
    //digit extraction of factorial
    for (; fac != 0; fac = fac / 10) 
    {
        a[i] = fac % 10;
        i++;
    }
    
    //sum of digits of factorial
    while (i > 0)
    {
        i--;
        sum = sum + a[i];
    }
    printf("%d",sum);
}