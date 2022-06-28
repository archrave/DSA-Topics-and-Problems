#include<iostream>
#include<vector>
using namespace std;

void transpose(vector<vector<int>>& a) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = i; j < a.size(); j++) {
            swap(a[i][j], a[j][i]);
        }
    }
}

// Time: O(n*n), Space: O(1)

// Algo: First we tranpose the matrix, then we swap the columns symmetrically.(imagine a vertical line)

//basically we're Reversing each row.

void rotate(vector<vector<int>>& matrix) {

    transpose(matrix);
    int n = matrix.size();
    int s = 0, e = n - 1;
    while (s <= e) {
        for (int i = 0; i < n; i++) {
            swap(matrix[i][s], matrix[i][e]);
        }
        s++;
        e--;
    }

    // Following code also works.
    // Reversing each row of the matrix

    // for (int i = 0; i < n; i++) {
    //     reverse(matrix[i].begin(), matrix[i].end());
    // }
}
int main() {
    vector<vector<int>> matrix = { {1,2,3},{4,5,6},{7,8,9} };
    int n = matrix.size();

    rotate(matrix);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}