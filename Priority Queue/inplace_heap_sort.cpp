#include<iostream>
#include<vector>
#include<utility>
using namespace std;


void buildMaxHeap(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int pI = (i - 1) / 2;
        int cI = i;

        //  Up heapify
        while (arr[pI] < arr[cI] && cI > 0) {
            swap(arr[pI], arr[cI]);
            cI = pI;
            pI = (cI - 1) / 2;
        }

    }
}

void pushMaxtoLast(vector<int>& arr) {

    int i = arr.size() - 1;
    while (i > 0) {
        swap(arr[0], arr[i]);
        int pI = 0;

        //  Down heapify
        while (true) {
            int c1 = 2 * pI + 1, c2 = 2 * pI + 2;
            int maxI = pI;
            if (c1 < i && arr[c1] > arr[maxI])
                maxI = c1;
            if (c2 < i && arr[c2] > arr[maxI])
                maxI = c2;
            if (pI == maxI)
                break;

            swap(arr[pI], arr[maxI]);
        }
        i--;
    }
}

void heapSort(vector<int>& arr) {
    buildMaxHeap(arr);
    pushMaxtoLast(arr);
}

int main() {
    // vector<int> arr = { 10, 34,  2, 5, 67, 15, 100 };
    vector<int> arr = { 5, 1, 2, 0, 8 };
    buildMaxHeap(arr);
    heapSort(arr);
    for (int i = 0;i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    return 0;
}