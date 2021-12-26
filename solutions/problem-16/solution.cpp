// Usage:
// g++ solution.cpp -std=c++11 -o bin
// ./bin

#include <vector>
#include <numeric>
#include <iostream>

constexpr int N = 1000;
constexpr int BASE = 10;

int main(int, char**) {
    std::vector<int> digits(1, 1);
    for (int k = 0; k < N; ++k) {
        int carry = 0;
        for (auto& digit : digits) {
            digit = digit * 2 + carry;
            carry = digit / BASE;
            digit = digit % BASE;
        }
        if (carry > 0) {
            digits.push_back(carry);
        }
    }
    const int sum = std::accumulate(digits.cbegin(), digits.cend(), 0);
    std::cout << sum << std::endl;
    return 0;
}

