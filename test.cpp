#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<vector<int>> da;
    vector<int> a,b;
    da.push_back(a);
    a.push_back(100);
    a.push_back(101);
    a.push_back(102);
    b = a;
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < b.size(); i++)
    {
        cout << b[i] << " ";
    }
    return 0;
}