    // Problem #2 - Even Fibonacci numbers
    // 0,1,2,3,5,8,13,21,34,55,89,144

    // Even Number - 0 2 8 34 144
    // Pattern Followed is - 
    //     8=4*2+0
    //     34=4*8+2
    //     144=4*34+8

#include<iostream>
using namespace std;
long long int fib(long long int n){
    long long int sum=0,l1,l2,temp;
    l1=0;   // second last even number
    l2=2;   // last even number
    
    if(n==2)
        return 2;
    while(l2<n){
            temp=l2;
            l2=4*l2+l1;  // formula for pattern
            l1=temp;
            if(l1%2==0)
                sum=sum+l1;
    }
    return sum;
}
int main(){
    long long int t,i,n;
    cin>>t; 
    for(i=0;i<t;i++){  // for 't' number of testcase
        cin>>n;        
        cout<<fib(n)<<endl;
    }
    return 0;
}
