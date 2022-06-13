#include <iostream>
#include <vector>
using namespace std;

void setMatrixZero(vector<vector<int>> &a)
{
    int m = a.size(), n = a[0].size();
    bool row[m] = {0}, col[n] = {0};
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 0)
            {
                row[i] = true;
                col[j] = true;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (row[i] || col[j])
                a[i][j] = 0;
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1, 12},
                                  {1, 0, 1, 23},
                                  {1, 1, 1, 1},
                                  {1, 1, 1, 0}};
    int m = matrix.size(), n = matrix[0].size();

    setMatrixZero(matrix);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}