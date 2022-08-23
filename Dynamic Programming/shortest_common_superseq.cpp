#include<bits/stdc++.h>
using namespace std;

string shortestSupersequence(string& a, string& b)
{
    int n = a.length(), m = b.length();
    int dp[n + 1][m + 1];
    int maxm = max(m, n);
    for (int i = 0; i <= maxm; i++)
    {
        if (i <= m)    dp[0][i] = 0;
        if (i <= n)    dp[i][0] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    int i = n, j = m;
    string common;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            common += a[i - 1];
            i--, j--;
        }
        else {
            if (dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        }
    }
    i = j = 0;
    string ans;
    cout << common << endl << endl;
    for (int k = common.length() - 1; k >= 0; k--) {
        while (a[i] != common[k]) {
            ans += a[i];
            i++;
        }
        while (b[j] != common[k]) {
            ans += b[j];
            j++;
        }
        ans += common[k];
        i++, j++;
    }
    while (i < n)
        ans += a[i], i++;
    while (j < m)
        ans += b[j], j++;
    return ans;
}

int main() {

    string a = "brute", b = "groot";
    cout << shortestSupersequence(a, b);
    return 0;
}