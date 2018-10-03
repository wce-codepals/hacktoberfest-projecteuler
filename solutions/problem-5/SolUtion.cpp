#include <iostream> 
using namespace std; 
     
int hcf(int a, int b) // HCF of 'a' and 'b'
{ 
    if (b == 0) 
        return a; 
    return hcf(b, a % b); 
} 
  
int findlcm(int arr[], int n) 
{
    int ans = 1;
    for (int i = 0; i < n; i++) 
        ans = (((arr[i] * ans)/(hcf(arr[i], ans))); 
  
    return ans; 
} 
  
int main()
{ 
    int arr1[] = {1,2,3,4,5,6,7,8,9,10};
    int arr2[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
   
    cout<<"Smallest number divisible by each of the numbers from 1 to 10 without any remainder "; 
    findlcm(arr1[],10);
   
    cout<<endl;
  
    cout<<"Smallest number divisible by each of the numbers from 1 to 20 without any remainder "; 
    findlcm(arr2[],20);
    
    return 0; 
} 
