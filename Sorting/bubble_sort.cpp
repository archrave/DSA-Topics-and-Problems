#include <iostream>
using namespace std;
int *bubbleSort(int arr[], int n)
{
    for (int i = 1; i <= n - 1; i++)
    {
        bool isUnsorted = false;
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isUnsorted = true;
            }
        }
        if (!isUnsorted)
        {
            break;
        }
    }
    return arr;
}
int main()
{
    int a[5] = {7, 2, 11, 6, 10};
    int *b = bubbleSort(a, 5);
    cout << "Sorted Array: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << b[i] << " ";
    }
    return 0;
}

// Worst Case: O(n*n)   (Reverse sorted array)
// Best Case: O(n)      (Already Sorted array)