#include <iostream>

using namespace std;

int main(){
  int num = 1000;
  const int THREE = 3;
  const int FIVE = 5;
  int total = 0;

  for(int count = 0; count < num; count++){
    if(count % THREE == 0 || count % FIVE == 0){
      total = total + count; 
    }
  }

  cout << total << "\n";
}