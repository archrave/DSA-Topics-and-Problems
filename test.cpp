#include<iostream>
using namespace std;
void fun1(int x) {
    cout << x << endl;
}

int main()
{
    int tr, b, x, y, value = 1;
    cin >> tr;
    for (x = 0; x < tr; ++y) {
        for (b = 1; bc <= tr - x; ++b)
            cout << " ";
        for (y = 0; y <= x; ++y) {
            if (y == 0 || x == 0)
                value = 1;
            else
                value = value * (x - y + 1) / y;
            printf("%4d", value);
        }
        cout << endl;
    }
    return 0;
}

