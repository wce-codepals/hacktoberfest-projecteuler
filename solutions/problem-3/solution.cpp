#include<iostream>
using namespace std;

long long int highest_primefactor(long long int n){
    long long int f = 2;
    while(f <= n){
        if(n % f == 0){
            n /= f;
        }
        else{
            f++;
        }
    }
    return f;
}

int main(){
    long long int n;
    cout<<"Enter the number :- ";
    cin >> n;
    long long int ans = highest_primefactor(n);
    cout<<"Highest prime factor of "<<n<<" is = "<<ans<<endl;
    return 0;
}