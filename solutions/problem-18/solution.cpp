#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
	ifstream file;
	file.open("numbers.txt");
	if (!file) {
		exit(1);
	}

	long long numbers[17][17]{0};
	for (int i = 1; i <= 15; i++)
	{
		for (int k = 1; k <= i; k++) {
			file >> numbers[i][k];
		}
	}

	for (int i = 1; i <= 15; i++) {
		for (int k = 1; k <= i; k++) {
			numbers[i][k] = numbers[i][k] + max(numbers[i - 1][k], numbers[i - 1][k-1]);
		}
	}

	long long maxI = -1000000;

	for (int i = 1; i <= 15; i++) {
		if (numbers[15][i] > maxI) { maxI = numbers[15][i]; }
	}
	cout << maxI;
	return 0;
}

