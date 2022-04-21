#include <iostream>
using namespace std;

void merge(int a[], int s, int mid, int e)
{
    int n1 = mid - s + 1, n2 = e - mid;
    int x[n1], y[n2];
    for (int i = 0; i < n1; i++)
    {
        x[i] = a[s + i];
    }
    for (int i = 0; i < n2; i++)
    {
        y[i] = a[mid + 1 + i];
    }
    int i = 0, j = 0, k = l;
    while (j < n1 && k < n2)
    {
        if (x[j] < y[k])
        {
            a[i] = x[j];
            j++;
        }
        else
        {
            a[i] = y[k];
            k++;
        }
        i++;
    }
    while (j <= n1)
    {
        a[i] = x[j];
        j++;
        i++;
    }
    while (k <= e - mid)
    {
        a[i] = y[k];
        k++;
        i++;
    }
}
void mergeSort(int a[], int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int mid = s + (e - s) / 2;

    mergeSort(a, s, mid);
    mergeSort(a, mid + 1, e);
    merge(a, s, mid, e);
}

int main()
{
    int a[] = {4, 1, 6, 2, 5, 3, 7};

    mergeSort(a, 0, 6);
    cout << "\nFINAL ARRAY: ";
    for (int i = 0; i < 6; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}