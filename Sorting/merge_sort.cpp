#include <iostream>
using namespace std;

void merge(int a[], int s, int mid, int e)
{
    // cout << "\n\ns, mid, e: " << s << " " << mid << " " << e;
    int n1 = mid + 1 - s, n2 = e - mid, curr = 0;
    int* a1 = new int[n1];
    int* a2 = new int[n2];

    for (int i = s; i <= mid; i++) {
        a1[curr] = a[i];
        curr++;
    }
    curr = 0;
    for (int i = mid + 1; i <= e; i++) {
        a2[curr] = a[i];
        curr++;
    }
    curr = s;
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (a1[i] <= a2[j]) {
            a[curr] = a1[i];
            i++;
        }
        else {
            a[curr] = a2[j];
            j++;
        }
        curr++;
    }
    while (i < n1) {
        a[curr] = a1[i];
        i++;
        curr++;
    }
    while (j < n2) {
        a[curr] = a2[j];
        j++;
        curr++;
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
    // int a[] = { 4, 1 };
    int a[] = { 4, 1, 6, 2, 5, 3, 7 };
    int s = 0, e = 6;
    // int s = 0, e = 1;
    mergeSort(a, s, e);
    cout << "\nFINAL ARRAY: ";
    for (int i = s; i <= e; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}