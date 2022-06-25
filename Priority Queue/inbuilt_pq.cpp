#include<iostream>
#include<vector>
#include<queue>
// #include<bits/stdc++.h>
using namespace std;
int main() {

    int arr[6] = { 1,234,5,71,34,4 };
    int n = 6;
    // Most functions are of O(logN) time.

    priority_queue<int> pq1;     // Implemented using MaxHeap

    /* Inserting elements in a min pq, one by one. T = O(logN)

    // priority_queue<int, vector<int>, greater<int> > pq;     // MIN PRIORITY QUEUE
    // for(int i = 0; i < arr.size(); i++)
    //     pq.push(a[i]);

    */

    //   Inserting all elements at once.  T = O(N)
    priority_queue<int, vector<int>, greater<int> > pq(arr, arr + n);     // MIN PRIORITY QUEUE

    pq.push(16);    //logN
    pq.push(1);
    pq.push(167);
    pq.push(7);
    pq.push(45);
    cout << "Size: " << pq.size() << endl;  //O(1)
    cout << "Top: " << pq.top() << endl;
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }








    return  0;
}