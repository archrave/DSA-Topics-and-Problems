#include<bits/stdc++.h>
using namespace std;

int maxP(vector<int>& prices, int t, int h) {

    if (h >= t) return 0;
    if (t == 0)  return 0;

    int a = prices[t] - prices[h];
    int b = maxP(prices, t - 1, h);
    int c = maxP(prices, t, h + 1);
    int d = maxP(prices, t - 1, h + 1);

    return max(max(a, b), max(c, d));

}
int maxProfit(vector<int>& prices) {
    int n = prices.size() - 1;
    return maxP(prices, n, 0);
}


// Optimum sol:

int maxProfit(vector<int>& prices) {
    int lsf = INT_MAX;
    int op = 0;
    int pist = 0;

    for (int i = 0; i < prices.size(); i++) {
        if (prices[i] < lsf) {
            lsf = prices[i];
        }
        pist = prices[i] - lsf;
        if (op < pist) {
            op = pist;
        }
    }
    return op;
}

int main() {
    vector<int> v = { 7,1,5,3,6,4 };
    cout << maxProfit(v);
    return 0;
}