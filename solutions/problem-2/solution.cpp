#include <bits/stdc++.h>
using namespace std;

int main() {
	int a[100000];
	a[0]=1;
	a[1]=1;
	
	for(int i=2;a[i]<4000000;i++)a[i]=a[i-1]+a[i-2];
	
	int sum = 0;
	
	for(int i=1;a[i]<4000000;i++){
	    if(a[i]%2==0)sum=sum+a[i];
	    
	}
	cout<<sum;
	
	return 0;
}
