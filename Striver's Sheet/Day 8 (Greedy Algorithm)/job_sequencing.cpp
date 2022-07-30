#include<bits/stdc++.h>


bool comparator(vector<int> v1, vector<int> v2) {
    if (v1[1] > v2[1])    return true;
    else if (v1[1] < v2[1])    return false;
    else if (v1[0] < v2[0])    return true;
    else    return false;
}
int jobScheduling(vector<vector<int>>& jobs)
{
    sort(jobs.begin(), jobs.end(), comparator);
    int profit = 0, time = 0;
    vector<int> arr(3001, 0);
    for (int i = 0; i < jobs.size(); i++) {
        int deadline = jobs[i][0];

        while (arr[deadline] != 0 && deadline > 1) {
            deadline--;
        }
        if (deadline == 1 && arr[deadline] == 1)
            continue;
        arr[deadline] = 1;
        profit += jobs[i][1];
    }
    return profit;
}
