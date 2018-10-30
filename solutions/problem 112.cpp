# bouncy numbers
#include<stdio.h>
using namespace std;
boolean check_bounce(int n) 
{  
  
   while (n != 0) 
   { 
       sum = sum + n % 10; 
       n = n/10; 
   } 
   return sum; 
} 
int main()
{
 double d=LDBL_MAX;
 int i;
 float pr;
 float sum;
 for( i=1 ; i<=d;++i)
 {
   
