#include <iostream>
using namespace std;
int main()
{
    char b[20];
    cin >> b;
    b[3] = 'x';
    // a[8] = '\0';
    cout << "string: " << b;
    return 0;
}