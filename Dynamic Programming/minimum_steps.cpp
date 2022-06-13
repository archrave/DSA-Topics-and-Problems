#include <iostream>
using namespace std;

// Memorization, Top-Down DP
int minimumSteps(int n, int arr[])
{
    if (n == 1)
    {
        return 0;
    }
    if (arr[n] != 0)
    {
        return arr[n];
    }
    int result;
    if (n % 3 == 0 && n % 2 == 0)
        result = min(minimumSteps(n / 3, arr), min(minimumSteps(n / 2, arr), minimumSteps(n - 1, arr))) + 1;
    else if (n % 3 == 0)
        result = min(minimumSteps(n / 3, arr), minimumSteps(n - 1, arr)) + 1;
    else if (n % 2 == 0)
        result = min(minimumSteps(n / 2, arr), minimumSteps(n - 1, arr)) + 1;
    else
        result = minimumSteps(n - 1, arr) + 1;
    arr[n] = result;
    return result;
}

// Iterative approach, Bottom Up DP:
int minimumSteps3(int n, int arr[])
{
    arr[1] = 0;
    arr[2] = arr[3] = 1;
    int i;
    for (i = 4; i <= n; i++)
    {
        if (i % 3 == 0 && i % 2 == 0)
            arr[i] = min(arr[i / 3], min(arr[i / 2], arr[i - 1])) + 1;
        else if (i % 3 == 0)
            arr[i] = min(arr[i / 3], arr[i - 1]) + 1;
        else if (i % 2 == 0)
            arr[i] = min(arr[i / 2], arr[i - 1]) + 1;
        else
            arr[i] = arr[i - 1] + 1;
        // cout << "arr[" << i << "]: " << arr[i] << endl;
    }
    return arr[n];
}
// Pure Recursion
int minimumSteps2(int n)
{
    if (n == 1)
    {
        return 0;
    }
    int result;
    if (n % 3 == 0 && n % 2 == 0)
        result = min(minimumSteps2(n / 3), min(minimumSteps2(n / 2), minimumSteps2(n - 1))) + 1;
    else if (n % 3 == 0)
        result = min(minimumSteps2(n / 3), minimumSteps2(n - 1)) + 1;
    else if (n % 2 == 0)
        result = min(minimumSteps2(n / 2), minimumSteps2(n - 1)) + 1;
    else
        result = minimumSteps2(n - 1) + 1;
    return result;
}

int main()
{
    int n = 265;
    int arr[n + 1] = {0};
    int arr1[n + 1] = {0};

    cout << endl;
    cout << minimumSteps(n, arr) << endl;
    cout << minimumSteps3(n, arr1) << endl;
    cout << minimumSteps2(n) << endl;
    return 0;
}