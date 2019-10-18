// Project Euler 2019
// Vinicius Rodrigues 17.10.2019
// Maximum Path Sum I : Problem 18
// R: 1074


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

const int size = 15;

int main()
{
	vector<vector<int>> matrix;
	string cmd;

	// input
	for(int i = 0; i < 15; i++)
	{
		matrix.push_back(vector<int>());
		for(int j = 0; j <= i; j++)
		{
			cin >> cmd;
			(--matrix.end()) -> push_back(atoi(cmd.c_str()));
		}
	}
	
	// varredura somando o maximo das duas celulas anteriores
	for(int i = 1; i < matrix.size(); i++)
	{
		for(int j = 0; j < matrix[i].size(); j++)
		{
			if(j != i and j > 0)
				matrix[i][j] += max(matrix[i-1][j], matrix[i-1][j-1]);
			else
				matrix[i][j] += j == i ? matrix[i-1][j-1] : matrix[i-1][j];
		}
	}

	auto triBase = *(--matrix.end());
	printf("%d\n", *max_element(triBase.begin(), triBase.end()));
}
