#include<iostream>
using namespace std;

int countAndMerge(int a[], int s, int mid, int e) {
    int count = 0;

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
            count += n1 - i;
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
    return count;
}

int countInversions(int arr[], int s, int e) {
    if (s >= e) {
        return 0;
    }
    int count = 0, mid = (e - s) / 2 + s;
    int a = countInversions(arr, s, mid);
    int b = countInversions(arr, mid + 1, e);
    count = a + b + countAndMerge(arr, s, mid, e);
    // count = a + b + merge(arr, s, mid, e);

    return count;
}

int main()
{
    // int arr[] = { 4,3,2,1,5 };
    // int arr[] = { 4,5,6,7,1,2,3 };
    int arr[] = { 1,3,2,3,1 };
    // int s = 0, e = 6;
    int s = 0, e = 4;
    int* temp = new int[e + 1];
    cout << countInversions(arr, s, e) << endl;
    // cout << merge_Sort(arr, temp, s, e);
    return 0;
}