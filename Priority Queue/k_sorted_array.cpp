#include<iostream>
#include<queue>
using namespace std;

void kSort(vector<int>& arr, int k) {
    priority_queue<int> pq;
    for (int i = 0; i < k;i++) {
        pq.push(arr[i]);
    }
    int s = k;
    for (int i = 0; i < arr.size(); i++) {

        arr[i] = pq.top();
        pq.pop();

        if (s < arr.size())
        {
            pq.push(arr[s]);
            s++;
        }
    }
}

int main() {
    vector<int> arr = { 12,15,7,4,9 ,2 };
    int k = 3;
    kSort(arr, k);
    for (int i = 0; i < arr.size();i++) {
        cout << arr[i] << " ";
    }
    return 0;
}