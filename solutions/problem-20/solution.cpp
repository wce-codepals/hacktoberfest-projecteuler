#include <iostream>

using namespace std;

int multiply(int x, int arr[], int res_size);

void factorial(int n)
{
    int arr[200];
    int answer = 0;
    arr[0] = 1;
    int arr_size = 1;

    for (int x=2; x<=n; x++)
    {
        arr_size = multiply(x, arr, arr_size);
    }

    for (int i=0; i<arr_size; i++)
    {
        answer += arr[i];
    }
    cout << answer;
}

int multiply(int x, int arr[], int arr_size)
{
    int carry = 0;

    for (int i=0; i<arr_size; i++)
    {
        int prod = arr[i] * x + carry;
        arr[i] = prod % 10;
        carry  = prod/10;
    }

    while (carry)
    {
        arr[arr_size] = carry%10;
        carry = carry/10;
        arr_size++;
    }
    return arr_size;
}

int main()
{
    factorial(100);
    return 0;
}
