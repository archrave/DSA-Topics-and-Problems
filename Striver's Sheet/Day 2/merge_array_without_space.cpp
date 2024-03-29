#include <bits/stdc++.h>
using namespace std;


void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if (n == 0)
        return;
    int i = m - 1, j = n - 1, k = m + n - 1;
    // if(m == 0) i = 0;
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        }
        else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }
    while (i >= 0) {
        nums1[k] = nums1[i];
        k--;
        i--;
    }
    while (j >= 0) {
        nums1[k] = nums2[j];
        k--;
        j--;
    }
}