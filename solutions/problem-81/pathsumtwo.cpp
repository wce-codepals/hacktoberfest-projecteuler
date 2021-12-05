// Project Euler 2019
// Vinicius Rodrigues 23.10.2019
// Path sum: Two Ways : Problem 81

#include <iostream>
#include <fstream>

using namespace std;

int matrix[80][80];

void makeMatrix(int m[80][80], string s)
{
	int l = 0, c = 0;
	string num = "";
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] == '\n' or s[i] == ',')
		{
			if(num.length() > 0)
			{
				m[l][c] = atoi(num.c_str());
				num = "";
			}
			if(s[i] == '\n') {l++; c=0;}
			else c++;
		}
		else
		{
			num += s[i];
		}
	}
}

void scanMatrix(int m[80][80])
{
	for(int i = 0; i < 80; i++)
	{
		for(int j = 0; j < 80; j++)
		{
			if(i != 0 and j != 0)
				m[i][j] += min(m[i-1][j], m[i][j-1]);
			else if(i == 0 and j != 0)
				m[i][j] += m[i][j-1];
			else if(i != 0 and j == 0)
				m[i][j] += m[i-1][j];
		}
	}
}

int main()
{
	ifstream file("p081_matrix.txt");
	string text = "", line = "";
	while(!file.eof())
	{
		getline(file, line);
		text += line + '\n';
	}

	makeMatrix(matrix, text);

	scanMatrix(matrix);

	cout << matrix[79][79] << endl;
}
