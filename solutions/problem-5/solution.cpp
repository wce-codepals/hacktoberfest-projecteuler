#include <iostream>

using namespace std;

#define FOR(i,a,b) for(int i(a);i<(b);i++)


int main(){
	
	int n = 2520, flag = 0 ; //the no has to be larger than this no
	while (flag == 0){
		int temp_flag = 1 ;
		FOR(i,2,21){
			if(n % i != 0){
				temp_flag = 0;
				break;
			}
		}
		if(temp_flag == 1){
			flag = 1;
			break;
		}
		n += 2; //since result will be an even no.
	}
	cout << n;
	return 0;
}