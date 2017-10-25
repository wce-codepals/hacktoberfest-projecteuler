// next_permutation example
#include <iostream>     // std::cout
#include <algorithm>    // std::next_permutation, std::sort

int main () {
  int myints[] = {1,2,3,4,5,6,7,8,9,0};

  std::sort (myints,myints+10);

  std::cout << "The possible permutations:\n";
  do {
    std::cout << myints[0] << ' ' << myints[1] << ' ' << myints[2] << ' ' << myints[3] << ' ';
	std::cout << myints[4] << ' ' << myints[5] << ' ' << myints[6] << ' ' << myints[7] << ' ';
	std::cout << myints[8] << ' ' << myints[9]  <<'\n';
  } while ( std::next_permutation(myints,myints+10) );

	std::cout << myints[0] << ' ' << myints[1] << ' ' << myints[2] << ' ' << myints[3] << ' ';
	std::cout << myints[4] << ' ' << myints[5] << ' ' << myints[6] << ' ' << myints[7] << ' ';
	std::cout << myints[8] << ' ' << myints[9]  <<'\n';
  return 0;
}
