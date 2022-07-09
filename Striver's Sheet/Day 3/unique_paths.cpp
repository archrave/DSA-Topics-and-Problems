#include<bits/stdc++.h>
using namespace std;

// int uniquePaths(int m, int n) {

//     // Bottom up DP:
//     int dp[m][n];
//     for (int i = 0; i < m;i++) {
//         for (int j = 0; j < n; j++) {
//             if (i == 0 || j == 0)
//                 dp[i][j] = 1;
//             else {
//                 dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//             }
//         }
//     }
//     return dp[m - 1][n - 1];
// }

// Optimal approach: using combinations

/* If we observe carefully, we're taking  m+n-1 steps in any path:


m = 2, n = 3
  0 1 2
0 * * *
1 * * *

or we can say, m-1 + n-1 steps.

So the total rightward steps = n - 1, Total downward steps = m - 1

SO if we're choosing n - 1 steps(only rightward) or m - 1 (only downward) from total of m-n-2 steps,
we get a total combinations of m - n - 2             m - n - 2
                                        C       or            C
                                         n-1                   m-1


This would be our answer.

*/

int uniquePaths(int m, int n) {

    /* Calculating  m - n - 2
                             C
                              n-1 */


    long long int ans = 1, j = n - 1;
    double calc = 1.0;
    for (long long int i = m + n - 2; i > m - 1; i--) {

        calc *= (i * 1.0 / j * 1.0);
        cout << calc << endl;
        j--;
    }
    ans = (long long int)calc;
    // cout<<"Calc" << calc;
    return int(calc);
}

int main() {
    int m = 6, n = 4;
    cout << uniquePaths(m, n);
    return 0;
}