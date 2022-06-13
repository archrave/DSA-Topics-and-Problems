#include <iostream>
#include <vector>
using namespace std;

int knapsack(int w[], int c[], int kn, int i)
{

    if (w[i] > kn)
    {
        return knapsack(w, c, kn, i - 1);
    }
    if (i < 0 || kn == 0)
    {
        return 0;
    }
    if (i == 0)
    {
        return c[i];
    }

    int currW = w[i];
    return max(knapsack(w, c, kn - currW, i - 1) + c[i], knapsack(w, c, kn, i - 1));
}

int solve(vector<int>& A, vector<int>& B, int C)
{
    int m = B.size(), n = C;
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {

            if (j == 0 || i == 0)
                dp[i][j] = 0;
            else if (B[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else if (i == 1)
            {
                dp[i][j] = A[i - 1];
            }
            else
            {
                int include = dp[i - 1][j - B[i - 1]] + A[i - 1];
                int exclude = dp[i - 1][j];
                dp[i][j] = max(include, exclude);
            }
        }
    }
    cout << endl;
    cout << endl;

    return dp[m][n];
}

int main()
{
    int n = 4, kn = 10;
    // int w[n] = {4, 3, 6, 1}, p[n] = {25, 10, 20, 3};
    // vector<int> w = {3, 1, 4};
    // vector<int> p = {20, 10, 25};
    vector<int> w = { 4, 5, 6, 15 };
    vector<int> p = { 25, 21, 20, 60 };
    // cout << knapsack(w, p, kn, n - 1);
    cout << solve(p, w, kn);
    return 0;
}