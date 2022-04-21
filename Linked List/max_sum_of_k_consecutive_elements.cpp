#include <iostream>
using namespace std;

int slidingWindow(int a[], int n, int k)
{
    int sum = 0, previous = 0, currSum = 0;

    for (int i = 0; i < k; i++)
    {
        sum += a[i];
    }
    // cout << " ini Sum: " << sum << endl;
    currSum = sum;
    for (int i = 1; i < n + 1 - k; i++)
    {
        currSum -= a[i - 1];
        currSum += a[i + k - 1];
        if (sum < currSum)
            sum = currSum;
    }
    return sum;
}

int main()
{
    int arr[9] = {1, 4, 2, 10, 23, 3, 1, 0, 20}, k = 4;
    int brr[4] = {100, 200, 300, 400};
    // k = 2;
    cout << endl
         << slidingWindow(arr, 9, 4) << endl;
    cout
        << slidingWindow(brr, 4, 2) << endl;
    return 0;
}