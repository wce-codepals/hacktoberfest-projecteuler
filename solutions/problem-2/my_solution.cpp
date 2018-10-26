#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> p = {
            1,
            2,
            3,
            5,
            8,
            13,
            21,
            34,
            55,
            89,
            144,
            233,
            377,
            610,
            987,
            1597,
            2584,
            4181,
            6765,
            10946,
            17711,
            28657,
            46368,
            75025,
            121393,
            196418,
            317811,
            514229,
            832040,
             1346269,
            2178309,
            3524578,
            };
    
    int answer = 0;
    for (int i = 0; i < p.size(); i++) {
        answer += (p[i] % 2 == 0) ? p[i] : 0;
    }

    cout << answer << endl;
}