#include <iostream>
using namespace std;
int main()
{

    int n = 11, a[11];
    for (int i = 0; i < 11; i++)
    {
        a[i] = 10 * (i + 1);
    }
    int *start = a, *end = a + 11;

    cout << "Before Swapping: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n / 2; i++)
    {
        int temp;
        temp = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = temp;
    }
    cout << "Before Swapping: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}