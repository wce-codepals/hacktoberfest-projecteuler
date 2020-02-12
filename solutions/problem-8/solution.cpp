#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        long long product=1,max_product=0;
        int i=0;
        for(i=0;i<(s.length()-k);i++){
            product=1;
            for(int j=i;j<(i+k);j++)
                 product*=(s[j]-48);
            if(product>max_product)
                max_product = product;
        }
        cout<<max_product<<endl;
    }
    return 0;
}

