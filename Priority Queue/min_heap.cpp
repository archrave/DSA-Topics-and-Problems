#include<iostream>
#include<vector>
#include<utility>
using namespace std;

class MinHeap {
    vector<int> arr;
    int nextIndex;

    void _insert(int data, int i)
    {
        if (i == 0) {
            return;
        }
        int parentI = (i - 1) / 2;
        if (arr[i] < arr[parentI]) {
            swap(arr[i], arr[(i - 1) / 2]);
            _insert(data, parentI);
        }

    }



public:
    MinHeap() {
        nextIndex = 0;
    }

    bool isEmpty() {
        return arr.size() == 0;
    }

    int getNextIndex() {
        return nextIndex;
    }

    void insert(int data) {
        arr.push_back(data);
        // _insert(data, nextIndex);
        nextIndex++;

        int cI = nextIndex - 1;
        int pI = (cI - 1) / 2;
        while (cI > 0 && arr[cI] < arr[pI]) {
            swap(arr[cI], arr[pI]);
            cI = pI;
            pI = (cI - 1) / 2;
        }
    }

    int remove() {
        if (nextIndex == 0) {
            cout << "\nUnderflow!\n";
        }
        swap(arr[0], arr[nextIndex - 1]);
        int ans = arr[nextIndex - 1];
        arr.pop_back();
        nextIndex--;

        int pI = 0;
        int c1 = 2 * pI + 1, c2 = 2 * pI + 2;
        while (c1 < nextIndex) {
            if (c2 >= nextIndex)
            {
                if (arr[pI] < arr[c1])
                    break;
                else {
                    swap(arr[pI], arr[c1]);
                    pI = c1;
                }
            }
            else if (arr[pI] < arr[c1] && arr[pI] < arr[c2])
                break;
            else {
                if (arr[c1] < arr[c2])
                {
                    swap(arr[pI], arr[c1]);
                    pI = c1;
                }
                else {
                    swap(arr[pI], arr[c2]);
                    pI = c2;
                }
            }
            c1 = 2 * pI + 1, c2 = 2 * pI + 2;
        }
        return ans;

    }

    void print()
    {
        cout << endl;
        for (int i = 0; i < nextIndex; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MinHeap m;
    m.insert(100);
    m.insert(10);
    m.insert(15);
    m.insert(4);
    m.insert(17);
    m.insert(21);
    m.insert(67);
    m.print();
    int n = 5;
    while (n--) {
        m.remove();
        m.print();
        cout << endl;
    }
    m.print();
    return 0;
}