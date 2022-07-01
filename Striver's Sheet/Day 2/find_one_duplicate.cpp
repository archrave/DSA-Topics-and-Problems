#include<bits/stdc++.h>
using namespace std;

// Linear Space:
// int findDuplicate(vector<int>& a) {
//     int n = a.size();
//     vector<bool> record(n,false);
//     for(int i = 0; i<n; i++){
//         if(!record[a[i]-1])   record[a[i]-1] = true;
//         else{
//             return a[i];
//         }
//     }
//     return a[0];
// }

// Constant Space usng Linked list cycle method
int findDuplicate(vector<int>& a) {
    int n = a.size();
    int s = a[0], f = a[0];
    do {
        s = a[s];
        f = a[a[f]];
    } while (s != f);

    f = a[0];
    while (s != f) {
        f = a[f];
        s = a[s];
    }
    return f;
}

// 1. Figure out that there is ought to be a cycle in thearray since one duplicate is present.
// 2. Run  a fast and a slow pointer fast moves two times, slow moves once.
// 3. we run the pointers such that the current element becomes the index of the next element
// 4. Run loop until both meet.
// 5. Set fast = a[0] i.e starting position.
// 6. Move both pointers one time only (in each iteration) and check when they become equal.
// 7. Return any of them when they become equal.