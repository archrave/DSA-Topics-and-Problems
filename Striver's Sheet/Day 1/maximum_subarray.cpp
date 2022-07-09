#include<bits/stdc++.h>
using namespace std;


// Kadane's Algorithm:
/*
    1. Initiate a sum, initiate a maxi variable and set it to first array element.
    2. We compare maxi and sum and set maxi = sum, whenever sum comes out to be higher.
    3. This algorithm works on the intution that we set our sum = 0, whenever it comes out to be negative.
    4. We return the maxi.
*/
int findMax(vector<int>& arr) {
    int maxi = arr[0], sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        maxi = max(sum, maxi);
        if (sum < 0)
            sum = 0;
    }
    return maxi;
}



int main() {
    vector<int> arr = { -2,1,-3,4,-1,2,1,-5,4 };
    cout << findMax(arr);
    // for (int i = 0; i < arr.size(); i++)
    //     cout << nums[i] << " ";
    return 0;
}