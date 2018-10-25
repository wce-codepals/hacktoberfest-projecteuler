#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <numeric>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int f = 0;
    int s = 1;
    int t = s + f;
    int sumEven = 0;

    for(int i = 0; i < 1000000 * 4; i ++) {
     if(t <= 1000000 * 4 && t % 2 == 0) {
         sumEven += t;
     }

     if(t >= 1000000 * 4)
        break;
      f = s; 
      s = t;
      t = s + f;
    }
  
    cout<<sumEven<<endl;
    return 0;
}