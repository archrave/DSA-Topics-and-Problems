#include <iostream>
#include <math.h>
using namespace std;

int fibbo(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    return fibbo(n - 1) + fibbo(n - 2);
}

int sumOfDigits(int n)
{
    if (n == 0)
        return 0;
    return (n % 10) + sumOfDigits(n / 10);
}
int countDigits(int n)
{
    if (n == 0)
        return 0;
    return 1 + countDigits(n / 10);
}
int multi(int m, int n)
{
    if (n == 1)
        return m;
    return m + multi(m, n - 1);
}
int countZeroes(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n % 10 == 0)
        return 1 + countZeroes(n / 10);
    else
        return countZeroes(n / 10);
}
double gsum(int n)
{
    if (n == 0)
        return 1;
    return gsum(n - 1) + (1 / pow(2, n));
}

bool checkIfSorted(int a[], int n)
{
    if (n == 1)
        return true;
    if (a[n - 1] < a[n - 2])
        return false;
    else
        return checkIfSorted(a, n - 1);
}

int main()
{
    int n = 10;
    cout << gsum(3);
    int a[5] = {10, 20, 30, 40, 45}, b[9] = {10, 2, 3, 4, 5, 6, 7, 8, 9}, c[1] = {1321}, d[2] = {3, 6}, e[2] = {19, 2};
    cout << "\na[] isSorted: " << checkIfSorted(a, 5) << endl;
    cout << "b[] isSorted: " << checkIfSorted(b, 9) << endl;
    cout << "c[] isSorted: " << checkIfSorted(c, 1) << endl;
    cout << "d[] isSorted: " << checkIfSorted(d, 2) << endl;
    cout << "d[] isSorted: " << checkIfSorted(e, 2) << endl;
    return 0;
}