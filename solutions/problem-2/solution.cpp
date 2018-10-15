//Add CPP solution to problem-2
#include <iostream>
using namespace std;

int main() {
	long long int i,j,k;
  long long int maxnumber,sum;
	cout<<"Enter maximum number of fibonacci series ";
	cin>>maxnumber;
  i = 0;j = 1;k = 0;sum = 0;
  while(k <= maxnumber) {
		if(k % 2 == 0)
    sum += k;
    k = i + j;
    i = j;
    j = k;
  }
  cout<<sum;
	return 0;
}
