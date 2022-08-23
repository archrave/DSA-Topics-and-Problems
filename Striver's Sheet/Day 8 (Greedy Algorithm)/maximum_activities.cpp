#include<bits/stdc++.h>


// Algorithm is similar to maximum meetings:
struct Activity {
    int s;
    int e;
};

bool comp(const Activity& m1, const Activity& m2) {
    return (m1.e < m2.e);
}

int maximumActivities(vector<int>& start, vector<int>& end) {

    int n = start.size();
    Activity m[n];
    for (int i = 0; i < n; i++)
        m[i].s = start[i], m[i].e = end[i];

    sort(m, m + n, comp);
    int cnt = 0, lastEnd = -1e9;
    for (int i = 0; i < n; i++) {
        if (m[i].s >= lastEnd) {
            cnt++;
            lastEnd = m[i].e;
        }
    }
    return cnt;
}