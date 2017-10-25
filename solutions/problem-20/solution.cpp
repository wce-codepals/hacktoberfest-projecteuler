#include <iostream>

using namespace std;

int main() {
	int fact = 1;
	int sum = 0;
	
	for (int i = 7; i > 0; i--) {
		fact *= i;
	}
	
	cout << "100! = " << fact << endl;
	
	do {
		sum += fact % 10;
		fact = fact /10;	
	} while (fact/10 >= 1);
	sum += fact % 10;
	
	cout << "The sum is equal to " << sum << endl;
	
}
