#include<bits/stdc++.h>
using namespace std;
/*
 7 6
 1 2
 2 4
 2 7
 7 6
 4 6
 3 5
*/

/*
12 14
1 2
2 3
1 4
3 4
4 5
5 6
6 7
6 9
7 8
8 9
8 10
10 11
10 12
11 12

*/

void checkBridgesDFS(vector<int> adj[], vector<int>& vis, vector<int>& tin, vector<int>& low, int node, int& timer, int parent) {

    vis[node] = 1;
    tin[node] = low[node] = timer++;
    // cout << "node : " << node << ", tin[node]: " << tin[node] << endl;
    for (auto it : adj[node]) {
        if (it == parent)   continue;
        else if (!vis[it]) {
            checkBridgesDFS(adj, vis, tin, low, it, timer, node);
            low[node] = min(low[node], low[it]);
            if (low[it] > tin[node]) {
                cout << node << " - " << it << endl;
            }
        }
        else {
            low[node] = min(low[node], tin[it]);
        }
    }
}

void checkBridges(vector<int> adj[], int n) {
    int timer = 1;
    vector<int> vis(n + 1, 0), tin(n + 1, 0), low(n + 1, 0);
    cout << "\nBridges:\n\n";
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0)
            checkBridgesDFS(adj, vis, tin, low, i, timer, -1);
    }

}
int main() {
    int n, m;
    cout << "\nEnter nodes and edges: ";
    cin >> n >> m;
    vector<int> adj[n + 1];
    cout << "\nEnter edges with spaces: \n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    checkBridges(adj, n);
    return 0;
}

