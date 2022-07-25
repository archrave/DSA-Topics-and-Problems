#include<bits/stdc++.h>
using namespace std;

vector<int> helper(vector<int>& num, int n) {
    vector<int> v;
    if (n == 0) {
        v.push_back(0);
        v.push_back(num[0]);
        return v;
    }
    v = helper(num, n - 1);
    int length = v.size();
    for (int i = 0; i < length; i++) {
        v.push_back(v[i] + num[n]);
    }
    return v;
}

vector<int> subsetSum(vector<int>& num)
{
    vector<int> ans = helper(num, num.size() - 1);
    sort(ans.begin(), ans.end());
    return ans;
}


int main() {
    vector<int> a = { 1,2 };
    vector<int> ans = subsetSum(a);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans.at(i) << " ";
    }
    return 0;
}