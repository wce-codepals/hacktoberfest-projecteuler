#include <iostream>
using namespace std;

void leap_year(bool &lp, int year) {
  if (year % 4 != 0) {
    lp = false;
  } else if (year % 100 != 0) {
    lp = true;
  } else if (year % 400 != 0){
    lp = false;
  } else {
    lp = true;
  }
}


int main(){
  int start_year = 1901;
  int end_year = 2000;

  int total_days = 0;

  while(start_year < end_year){
    bool leap = false;
    leap_year(leap, start_year);
    if(leap){
      total_days += 366;
    } else {
      total_days += 365;
    }
    start_year++;
  }

  int total_sundays = total_days / 7;
  cout << total_sundays << endl;
  return 0;
}
