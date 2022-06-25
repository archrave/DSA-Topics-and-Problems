#include<iostream>
#include<queue>
using namespace std;

void kSmallest(vector<int>& arr, int k) {
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
        pq.push(arr[i]);

    for (int i = k; i < arr.size(); i++) {
        if (pq.top() > arr[i])
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    cout << endl;
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

int main() {
    vector<int> arr = { 8, 5, 12, 10, 0, 1, 6, 9 };
    vector<int> arr2 = { 3 ,2, 1, 0, 5, 4, 9, 17, 21 };
    int k = 4;
    kSmallest(arr, k);
    kSmallest(arr2, k);

    return 0;
}