#include <bits/stdc++.h>
using namespace std;

int main(){
	// a, b, sqrt(a*a+b*b)
	// a+b+sqrt(a*a+b*b)=1000
	for(int a=1;a<=1000;a++){
		for(int b=a+1;b<=1000;b++){
			int c = sqrt(a*a+b*b);
			if(a+b+c==1000 && c*c==a*a+b*b){
				cout<<a<<" "<<b<<" "<<c<<endl;
				cout<<a*b*c<<endl;

			}
		}
	}
}
