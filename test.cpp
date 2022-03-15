#include <bits/stdc++.h>
using namespace std;

void printblah(vector<int> &a)
{
    a[0] = 10;
}
int main()
{
    string a = "Absolute";
    cout << a.substr(0, 4) + " 1111 " + a.substr(2, 0);
    return 0;
}