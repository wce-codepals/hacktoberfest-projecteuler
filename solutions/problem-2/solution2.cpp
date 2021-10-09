#include <iostream>
using namespace std; 
int main() {
  int firstTerm = 1;
  int secondTerm = 2; 
  int totalSum = 0; 
  while (firstTerm < 4000000)
  {
    if (firstTerm%2 == 0)
    {
      totalSum += firstTerm; 
    }
    int tempFirstTerm = firstTerm; 
    firstTerm = secondTerm; 
    secondTerm = tempFirstTerm + secondTerm; 
  }
  cout << totalSum << endl; 
}