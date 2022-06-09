#include <iostream>
#include <vector>
using namespace std;

void printTraingle(vector<vector<int>> matrix)
{
    int n = matrix.size();
    int spaceCount = n - 1;
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < spaceCount; j++)
            cout << " ";
        for (int j = 0; j < matrix[i].size(); j++)
            cout << matrix[i][j] << " ";
        for (int j = 0; j < spaceCount; j++)
            cout << " ";
        cout << endl;
        spaceCount--;
    }
    cout << endl;
}

vector<vector<int>> pascalsTriangle(int n)
{
    vector<vector<int>> matrix;
    if (n == 0)
        return matrix;
    if (n == 1)
    {
        vector<int> row;
        row.push_back(1);
        matrix.push_back(row);
        return matrix;
    }
    if (n == 2)
    {
        vector<int> row;
        for (int i = 1; i <= 2; i++)
        {
            row.push_back(1);
            matrix.push_back(row);
        }
        return matrix;
    }
    matrix = pascalsTriangle(n - 1);
    vector<int> row(n, 0);
    row[0] = 1;
    row[n - 1] = 1;
    int l = (n % 2 == 0) ? (n / 2) - 1 : n / 2;
    for (int i = 1; i <= l; i++)
    {
        int curr = matrix[n - 2][i - 1] + matrix[n - 2][i];
        row[i] = curr;
        row[n - 1 - i] = curr;
    }

    matrix.push_back(row);
    return matrix;
}

int main()
{
    int n = 10;
    vector<vector<int>> matrix;
    matrix = pascalsTriangle(5);
    cout << "what happennd\n\n";
    printTraingle(matrix);
    return 0;
}