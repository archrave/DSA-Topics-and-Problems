#include <iostream>
using namespace std;

int binarySearch(int a[], int n, int key)
{
    int start = 0, end = n - 1, mid;
    while (start <= end)
    {
        // mid = (start + end) / 2;
        mid = start + (end - start) / 2; // This is a better apprach since '(start + end)' might result in interger overflow.
        if (key == a[mid])

            return mid;

        else if (key < a[mid])
            end = mid - 1;

        else
            start = mid + 1;
    }
    return -1;
}
int main()
{
    int a[5] = {2, 6, 7, 10, 15}, key;
    cout << "Enter the key that you want to search for: ";
    cin >> key;
    int result = binarySearch(a, 5, key);

    if (result == -1)
    {
        cout << "Key doesn't exist in the given array!" << endl;
    }
    else
        cout << "The key is present at position " << result << endl;

    return 0;
}