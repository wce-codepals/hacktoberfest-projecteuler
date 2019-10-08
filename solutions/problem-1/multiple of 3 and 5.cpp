#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long int  n,s;
        cin >> n;
        s=(3*(((n-1)/3)*(((n-1)/3)+1))+5*(((n-1)/5)*(((n-1)/5)+1))-15*(((n-1)/15)*(((n-1)/15)+1)))/2;
        cout<<s<<endl;
    }
    return 0;
}
