#include <iostream>
using namespace std;
int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}
int main()
{
    int a[5] = {7, 2, 11, 6, 10}, key;
    cout << "Enter the key that you want to search for: ";
    cin >> key;
    int result = linearSearch(a, 5, key);

    if (result == -1)
    {
        cout << "Key doesn't exist in the given array!" << endl;
    }
    else
        cout << "The key is present at position " << result << endl;

    return 0;
}