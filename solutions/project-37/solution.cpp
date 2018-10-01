#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int x) {
  //Check if a number is prime

  if(x <= 1) return false;
  if(x == 2 || x == 3) return true;
  else if (x % 2 == 0) return false;

  else {
	for (int i = 3; i < (int)sqrt((float)x)+1; i++) {
    		if (x % i == 0) return false;
	}
  }

  return true;
}

bool truncatableCheck(int x) {
    if (x<=0) return false;

    //Get the length of the number

    int len = 0;
    int tmp = x;
    while (tmp !=0)
    {
        len ++;
        tmp /= 10;
    }

    //Truncate from right and check if is prime

    tmp = x;
    while (tmp != 0) {

        if (isPrime(tmp) != true) {

            return false;
        }

        tmp /= 10;
    }

    //Truncate from left and check if is prime

    tmp = x;
    while(len > 1 ) {

        int y = tmp % (int)pow((float)10, len-1);

        if (isPrime(y) != true) {
            return false;
        }

        len--;
    }

    return true;
}

int main() {

      int numbers = 0;
      int sum = 0;
      int i = 8;

      while(numbers < 11) {

          if (truncatableCheck(i)) {
              sum += i;
              numbers ++;
              cout << i << endl;
          }
          i++;
      }
      cout << "Sum "<< sum << endl;
      return 0;
}
