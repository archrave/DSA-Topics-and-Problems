#include <bits/stdc++.h>
using namespace std;

int sum(int a[], int n)
{
    if (n == 0)
        return 0;
    return a[n - 1] + sum(a, n - 1);
}

bool isPresent(int a[], int n, int key)
{
    if (n == 0)
        return false;

    if (a[n - 1] == key)
        return true;
    else
        return isPresent(a, n - 1, key);
}

int firstIndex(int a[], int n, int key, int i)
{
    if (i == n)
        return -1;
    if (a[i] == key)
        return i;
    else
        return firstIndex(a, n, key, i + 1);
}
void printAllPositions(int a[], int n, int key, int i)
{
    if (i == n)
    {
        return;
    }
    if (a[i] == key)
        cout << i << " ";
    printAllPositions(a, n, key, i + 1);
}
int countAllPositions(int a[], int n, int key)
{
    if (n == 0)
    {
        return 0;
    }
    if (a[n - 1] == key)
        return 1 + countAllPositions(a, n - 1, key);
    else
        return countAllPositions(a, n - 1, key);
}

int lastIndex(int a[], int n, int key)
{
    if (n == 0)
        return -1;
    if (a[n - 1] == key)
        return n - 1;
    else
        return lastIndex(a, n - 1, key);
}

bool checkPalindrome(int a[], int s, int e)
{
    if (s >= e)
        return true;
    if (a[s] != a[e])
        return false;
    return checkPalindrome(a, s + 1, e - 1);
}

int main()
{
    int a[5] = {20, 10, 10, 40, 10};
    // printAllPositions(a, 5, 10, 0);
    // cout << endl;
    // printAllPositions(a, 5, 40, 0);
    // cout << endl;
    // printAllPositions(a, 5, 1, 0);
    // cout << endl;
    int a1[9] = {1, 2, 5, 1, 0, 1, 5, 2, 1}, b1[6] = {1, 3, 5, 5, 3, 1}, b3[8] = {1, 2, 3, 4, 4, 3, 3, 1}, b4[1] = {100};
    cout << checkPalindrome(a1, 0, 8) << endl;
    cout << checkPalindrome(b1, 0, 5) << endl;
    cout << checkPalindrome(b3, 0, 7) << endl;
    cout << checkPalindrome(b4, 0, 0) << endl;
    return 0;
}

// isPresent(5)
//     isPresent(4)
//         isPresent(3)
