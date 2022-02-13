#include <iostream>
using namespace std;

int *selectionSort(int *arr, int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        int min = INT32_MAX, minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                minIndex = j;
            }
        }
        if (arr[i] > arr[minIndex])
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }

    return arr;
}
int main()
{
    int a[5] = {7, 5, 3, 6, 8};
    int *b = selectionSort(a, 5);
    cout << "Sorted Array: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << b[i] << " ";
    }
    return 0;
}