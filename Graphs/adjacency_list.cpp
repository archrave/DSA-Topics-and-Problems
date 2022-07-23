#include<bits/stdc++.h>
using namespace std;


void bfs(vector<int> adj[], int n) {

    vector<int> vis(n + 1, 0);
    cout << "\nBFS: ";
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            while (!q.empty()) {
                int k = q.front();
                q.pop();
                cout << k << " ";
                for (auto it : adj[k]) {
                    if (vis[it] == 0) {
                        q.push(it);
                        vis[it] = 1;
                    }
                }
            }
        }
    }
    cout << endl;
}

void dfsHelper(vector<int> adj[], vector<int>& vis, int k) {
    cout << k << " ";
    vis[k] = 1;
    for (auto it : adj[k]) {
        if (!vis[it])
            dfsHelper(adj, vis, it);
    }
    return;
}
void dfs(vector<int> adj[], int n) {
    cout << "DFS: ";
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (!vis[i])
            dfsHelper(adj, vis, i);
    }
}

int main() {
    int n, m;
    cout << "\nEnter nodes and edges: ";
    cin >> n >> m;

    vector<int> adj[n + 1];

    // For a weighted graph:
    // vector<int> adj[n + 1];

    cout << "\nEnter edges with spaces: \n";
    for (int i = 0; i < m; i++) {
        // cout << "i: " << i << endl;
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        // For a weighted graph:
        // adj[u].push_back({v, wt});
        // adj[v].push_back({u, wt});

    }
    bfs(adj, n);
    dfs(adj, n);

    return 0;
    /*
    7 6
    1 2
    2 3
    2 7
    7 5
    3 5
    4 6
    */
    /*
    7 6
    1 2
    2 4
    2 7
    7 6
    4 6
    3 5
    */
}
