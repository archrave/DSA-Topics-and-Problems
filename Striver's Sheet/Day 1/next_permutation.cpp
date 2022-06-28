#include <bits/stdc++.h>
using namespace std;

void reverseRest(vector<int>& a, int s, int e) {
    auto mid = (s + e) / 2;
    while (s < e) {
        swap(a[s], a[e]);
        s++;
        e--;
    }
}

void nextPermutation(vector<int>& nums) {

    int breakPoint, i = 0, n = nums.size();

    for (i = n - 1; i > 0; i--) {

        if (nums[i - 1] < nums[i]) {
            breakPoint = i - 1;
            break;
        }
    }
    cout << breakPoint;
    if (i == 0) {
        reverseRest(nums, 0, n - 1);
        return;
    }

    int oneAbove = n - 1;
    for (i = n - 1; i > breakPoint; i--) {

        if (nums[i] > nums[breakPoint]) {
            oneAbove = i;
            break;
        }

    }

    swap(nums[oneAbove], nums[breakPoint]);
    reverseRest(nums, breakPoint + 1, n - 1);

}

int main() {

    vector<int> arr = { 1,2,4,3 };
    nextPermutation(arr);
    for (int i = 0; i < arr.size(); i++)
        cout << nums[i] << " ";
    return 0;
}