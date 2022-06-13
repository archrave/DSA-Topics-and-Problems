#include <bits/stdc++.h>
using namespace std;

int minD(string s1, string s2, int i, int j, int **dp)
{
    if (i == 0 && j == 0)
    {
        return 0;
    }
    if (i == 0)
    {
        dp[i][j] = j;
        return j;
    }
    if (j == 0)
    {
        dp[i][j] = i;
        return i;
    }

    if (dp[i][j] > -1)
    {
        return dp[i][j];
    }

    if (s1[i - 1] == s2[j - 1])
    {
        dp[i][j] = minD(s1, s2, i - 1, j - 1, dp);
    }
    else
    {
        dp[i][j] = 1 + min(minD(s1, s2, i, j - 1, dp), min(minD(s1, s2, i - 1, j, dp), minD(s1, s2, i - 1, j - 1, dp)));
    }
    return dp[i][j];
}

int minDistance(string word1, string word2)
{
    int m = word1.length(), n = word2.length();
    int **dp = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        dp[i] = new int[n + 1];
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = -1;
        }
    }
    int ans = minD(word1, word2, m, n, dp);

    cout << endl;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << dp[i][j] << " ";
        }
        delete[] dp[i];
        cout << endl;
    }
    cout << endl;

    delete[] dp;
    return ans;
}

int main()
{
    string s1 = "horse", s2 = "ros";
    cout << minDistance(s1, s2);
    return 0;
}