#include<bits/stdc++.h>
using namespace std;

// Worst solution: O(logN) time, O(N) space in worst case.

// class Train {
// public:
//     int AT;
//     int DT;

//     Train(int at, int dt) {
//         AT = at;
//         DT = dt;
//     }
// };

// bool comparator(Train t1, Train t2) {
//     if (t1.AT < t2.AT)    return true;
//     else if (t1.AT > t2.AT)    return false;
//     else if (t1.DT < t2.DT)    return true;
//     else   return false;
// }
// int calculateMinPatforms(int at[], int dt[], int n) {
//     vector<Train> trains;
//     vector<int> ans;

//     for (int i = 0; i < n; i++) {
//         Train t(at[i], dt[i]);
//         trains.push_back(t);
//     }
//     sort(trains.begin(), trains.end(), comparator);
//     int lastTime = -1, maxm = 1, count = 1, j = 0;
//     priority_queue<int, vector<int>, greater<int> > pq;     // MIN PRIORITY QUEUE
//     pq.push(trains[0].DT);
//     for (int i = 1; i < n; i++) {
//         // Logic here:
//         if (trains[i].AT > pq.top()) {
//             pq.pop();
//         }
//         else {
//             maxm++;
//         }
//         pq.push(trains[i].DT);

//     }
//     return maxm;
// }


// Sorting both trains since we only want to parse through the time and count platforms. O(1) space.
int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at, at + n);
    sort(dt, dt + n);

    int maxm = 1, j = 0;
    for (int i = 1; i < n; i++) {
        if (at[i] > dt[j])
            j++;
        else
            maxm++;
    }
    return maxm;
}