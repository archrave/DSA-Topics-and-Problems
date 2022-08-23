// Push all negative elements to the left of the array
#include<bits/stdc++.h>
using namespace std;

void separateNegativeAndPositive(vector<int>& nums) {
    int s = 0, n = nums.size(), e = nums.size() - 1;

    while (s < e) {
        while (nums[s] < 0)    s++;
        while (nums[e] >= 0)    e--;
        if (s >= e || s > n - 1 || e < 0)    break;
        swap(nums[s], nums[e]);
        s++;
        e--;
    }
    //     cout<<" HAHHHA: "<<endl;
    //     for(auto it:nums)
    //         cout<<it<<" ";

}
int main() {
    vector<int> a = { -44 ,-32 };
    separateNegativeAndPositive(a);
    for (auto it : a)
        cout << it << " ";
    return 0;
}