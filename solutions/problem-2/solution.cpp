#include <iostream>
#include <vector>
using namespace std;

vector <int> fib(10000,-1);

int dp_sol(int n){
	//if already computed
	if(fib[n]!=-1){
		return fib[n];
	}
	//base case
	if(n==0 || n==1){
		return fib[n]=1;
	}
	//recursive case 
	return fib[n] = dp_sol(n-1)+dp_sol(n-2); 
}

int main(){
	
	int res = 0; //to store the sum required
	int i = 2; //since 1st even value is 2 which is 2nd term
	while(dp_sol(i)<=4000000){ //we only need to consider terms till 4 million 
		// only if the term is even, add it to the result
		if(dp_sol(i)%2 == 0){
			res += dp_sol(i);
		}
		i ++;
	}
	cout << res;
	return 0;
}