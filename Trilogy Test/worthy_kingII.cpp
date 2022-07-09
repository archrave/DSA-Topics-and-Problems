#include<bits/stdc++.h>
using namespace std;

int worthyKing(vector<int> A) {
    sort(A.begin(), A.end());
    int n = A.size(), totalDays = 0, x = 1, days = 0;
    for (int i = 0; i < n; i++) {
        days = ceil((double)A[i] / (double)x);
        totalDays += days;
        x++;
        cout << days << " ; ";
    }
    return totalDays;
}

int main() {
    vector<int> v = { 4,3,1 };
    cout << worthyKing(v);
    return 0;
}