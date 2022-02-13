#include <iostream>
using namespace std;

bool isSafe(int x, int y, int n, int (*arr)[5])
{
    if (x < n && y < n && arr[x][y] == 1)
    {
        return true;
    }
    else
        return false;
}

bool ratInAMaze(int n, int (*arr)[5], int x, int y, int (*solArr)[5])
{
    if (x == n - 1 && y == n - 1)
    {
        solArr[x][y] = 1;
        return true;
    }
    if (isSafe(x, y, n, arr))
    {
        solArr[x][y] = 1;
        if (ratInAMaze(n, arr, x + 1, y, solArr))
        {
            return true;
        }
        if (ratInAMaze(n, arr, x, y + 1, solArr))
        {
            return true;
        }
        solArr[x][y] = 0;
        return false;
    }
    return false;
}

int main()
{
    // int **a = new int*[5] ;
    int arr[5][5] =
        {
            {1,
             0,
             1,
             0,
             1},
            {1, 1, 1, 1, 1},
            {0, 1, 0, 1, 0},
            {1, 0, 0, 1, 1},
            {1, 1, 1, 0, 1},
        };
    int solA[5][5] = {

        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
    };
    int x = 0, y = 0, n = 5;
    bool israt = ratInAMaze(n, arr, x, y, solA);
    cout << "isRat: " << israt << endl;
    if (ratInAMaze(n, arr, x, y, solA))
    {
        for (int i = 0; i < n; i++)

        {
            for (int j = 0; j < n; j++)
            {
                cout << solA[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "Rat can't pass the maze!";
    }
    return 0;
}