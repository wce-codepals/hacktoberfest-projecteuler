#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> deserializeLine(const string &line)
{
    vector<int> result;

    int i = 0;
    while (i < line.size()) {
        int num = 0;
        while (i < line.size() && line[i] != ',') {
            num = (num * 10) + (line[i] - '0');
            i++;
        }
        i++;
        result.push_back(num);
    }

    return result;
}

bool deserialize(const string &filename, vector<vector<int>> &matrix)
{
    bool success = false;

    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            matrix.push_back(deserializeLine(line));
        }
        file.close();

        success = true;
    }

    return success;
}

// This is the algorithmic part, using a bottom-up dynamic programming approach.
void solve(const vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> dp = matrix;
    for (int i = rows - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= 0; j--) {
            int best = INT_MAX;
            if (i + 1 < rows) best = min(best, dp[i + 1][j]);
            if (j + 1 < cols) best = min(best, dp[i][j + 1]);
            dp[i][j] += best == INT_MAX ? 0 : best;
        }
    }

    cout << dp[0][0] << endl;
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        cout << "Usage: ./solution input_matrix.txt" << endl;
        exit(1);
    }

    vector<vector<int>> matrix;
    if (!deserialize(argv[1], matrix)) {
        cout << "Input file could not be found!" << endl;
        exit(1);
    }

    if (matrix.empty()) {
        cout << "The matrix is empty!" << endl;
        exit(1);
    }

    solve(matrix);

    return 0;
}
