#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n) {
    double ans = 1;
    long long int m = n;
    for (long long int i = 1; i <= abs(m); i++)
        ans *= x;

    ans = n >= 0 ? ans : 1 / ans;
    return ans;
}

int main()
{
    double x = 0.00001;
    int n = 10000;
    cout << myPow(x, n);
    return 0;
}

