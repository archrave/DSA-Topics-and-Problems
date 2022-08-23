#include<bits/stdc++.h>
using namespace std;

int main() {

    vector<int> arr = { 1,2,7,7,4,3,6 };
    vector<int> ans;
    int sum = 0, cnt = 0, k = 3;
    for (int i = 0; i < arr.size() - 1; i++) {
        sum += arr[i];
        cnt++;
        cout << "sum: " << sum << endl;
        if (arr[i] == arr[i] + 1 || cnt == k)
        {
            if (cnt == k)   ans.push_back(sum);
            sum = 0;
            cnt = 0;
        }
    }

    if (ans.size() == 0)   cout << -1 << endl;
    int maxm = ans[0];
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
        maxm = max(maxm, ans[i]);
    }
    cout << "\n\nMax: " << maxm;
    return 0;
}