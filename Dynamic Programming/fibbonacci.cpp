#include <iostream>
using namespace std;

int fibbonacci(int n, int arr[])
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    // Reuse
    if (arr[n] > 0)
    {
        return arr[n];
    }

    // Store
    int output = fibbonacci(n - 1, arr) + fibbonacci(n - 2, arr);
    arr[n] = output;
    return output;
}
int main()
{
    int n = 10;
    int arr[n + 1] = {0};
    cout << fibbonacci(n, arr) << endl;
    return 0;
}