#include <bits/stdc++.h>
using namespace std;

void multiply(vector<int> &v, int x)
{
    int carry = 0, res;
    int size = v.size();
    for (int i = 0 ; i < size ; i++)
    {
        // Calculate res + prev carry
        int res = carry + v[i] * x;

        // updation at ith position
        v[i] = res % 10;
        carry = res / 10;
    }
    while (carry != 0)
    {
        v.push_back(carry % 10);
        carry /= 10;
    }
}

// Returns sum of digits in n!
int findSumOfDigits(int n)
{
    vector<int> v;     // create a vector of type int
    v.push_back(1);    // adds 1 to the end

    // One by one multiply i to current vector
    // and update the vector.
    for (int i=1; i<=n; i++)
        multiply(v, i);

    // Find sum of digits in vector v[]
    int sum = 0;
    int size = v.size();
    for (int i = 0 ; i < size ; i++)
        sum += v[i];
    return sum;
}

// Driver code
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        cout << findSumOfDigits(n);
        return 0;
      }
}
