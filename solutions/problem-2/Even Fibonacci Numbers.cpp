#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long n,s=2,s1=0,s2,s3=2;
        cin >> n;
        while(s<=n)
        {
            s2=s*4+s1;
            s1=s;
            s=s2;
            if(s2>n)
                break;
            else
                s3+=s2;
        }
        cout<<s3<<endl;
    }
    return 0;
}
