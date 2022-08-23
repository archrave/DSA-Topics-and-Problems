#include<bits/stdc++.h>
using namespace std;

void printS(int i, int n, int arr[], vector<int>& v) {
    if (i == n) {
        for (auto it : v) cout << it << " ";
        cout << endl;
        return;
    }

    // cout << arr[i] << " ";
    v.push_back(arr[i]);
    printS(i + 1, n, arr, v);
    v.pop_back();
    printS(i + 1, n, arr, v);
}
int main() {
    int n = 3, arr[3] = { 3,1,4 };
    vector<int> v;
    printS(0, n, arr, v);
    return 0;
}