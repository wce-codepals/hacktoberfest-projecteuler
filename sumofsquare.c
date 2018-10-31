#include <stdio.h> 
int summation(int n) 
{ 
    return (n * (n + 1) *  
           (2 * n + 1)) / 6; 
} 
  

int main() 
{ 
    int n;
    printf("Enter n\n");
    scanf("%d",&n);
    printf("%d", summation(n)); 
    return 0; 
} 
