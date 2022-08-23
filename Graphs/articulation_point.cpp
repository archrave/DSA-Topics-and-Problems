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

void findArticulationPointsDFS(vector<int> adj[], vector<int>& vis, vector<int>& tin, vector<int>& low, vector<int>& artPoints, int node, int& timer, int parent) {

    int child = 0;
    vis[node] = 1;
    tin[node] = low[node] = timer++;
    for (auto it : adj[node]) {
        if (it == parent)   continue;
        if (!vis[it]) {
            findArticulationPointsDFS(adj, vis, tin, low, artPoints, it, timer, node);
            // If a dfs call for a node is completed, we can definitely say that it is a child of the 'node'.
            low[node] = min(low[node], low[it]);
            if (low[it] >= tin[node] && parent != -1) {
                artPoints[node] = 1;
            }
            child++;
        }
        else
            low[node] = min(low[node], tin[it]);
    }
    if (parent == -1 && child > 1)
        artPoints[node] = 1;
}

vector<int> findArticulationPoints(vector<int> adj[], int n) {
    int timer = 0;
    vector<int> vis(n + 1, 0), tin(n + 1, -1), low(n + 1, -1), artPoints(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0)
            findArticulationPointsDFS(adj, vis, tin, low, artPoints, i, timer, -1);
    }
    return artPoints;
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
    vector<int> ans = findArticulationPoints(adj, n);
    cout << "\nArticulation Points:\n";
    for (int i = 1; i <= n; i++) {
        if (ans[i] == 1) cout << i << " ";
    }
    return 0;
}

