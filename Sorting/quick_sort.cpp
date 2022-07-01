#include <bits/stdc++.h>
using namespace std;

int partition(int a[], int s, int e)
{
    int pivot = 0;
    for (int i = s; i < e; i++)
    {
        if (a[i] < a[e])
        {
            pivot++;
        }
    }
    swap(a[pivot], a[e]);
    int i = s, j = e;
    while (i < pivot && j > pivot)
    {
        if (a[i] >= a[pivot])
        {
            if (a[j] < a[pivot])
            {
                swap(a[i], a[j]);
                i++;
            }
            j--;
        }
        else
        {
            if (a[j] >= a[pivot])
            {
                j--;
            }
            i++;
        }
    }
    return pivot;
}
// int partition(int a[], int s, int e)
// {
//     int i = s;
//     int pivot = a[e];
//     for (int j = s; j < e; j++)
//     {
//         if (a[j] < pivot)
//         {
//             swap(a[i], a[j]);
//             i++;
//         }
//     }
//     swap(a[i], a[e]);
//     return i;
// }

void quickSort(int a[], int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int p = partition(a, s, e);
    quickSort(a, s, p - 1);
    quickSort(a, p + 1, e);
}

int main()
{
    int n = 6;
    int a[7] = { 8, 5, 2, 1, 7, 3, 4 };
    // int a[2] = {2, 1};
    // n = 1;
    quickSort(a, 0, n);
    cout << partition(a, 0, n);
    cout << endl
        << endl;
    for (int i = 0; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}