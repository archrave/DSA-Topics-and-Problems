#include<bits/stdc++.h>
using namespace std;


bool detectCycle(vector<int> adj[], int n) {
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++) {

        if (!vis[i]) {
            queue<pair<int, int>> q;
            q.push({ i, -1 });
            vis[i] = 1;
            while (!q.empty()) {
                int node = q.front().first;
                int parent = q.front().second;
                q.pop();
                for (auto it : adj[node]) {
                    if (!vis[it]) {
                        // Logic is to store the parent as the second part of the pair
                        q.push({ it, node });
                        vis[it] = 1;
                    }
                    // And checking if the repeated element in the vis[] array is the same as its parent or not. If not there's a cycle.
                    // (and if yes that simply indicates the bidirectional nature of the edge [undirected graph])
                    else if (it != parent) {
                        return true;
                    }
                }
            }

        }

    }
    return false;
}

void detectHelper(vector<int>, ) {

}
void detectCycleDFS(vector<int> adj[], int n) {

}
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

    string s = (detectCycle(adj, n)) ? "\ntrue" : "\nfalse";
    cout << endl << s;
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

    /*
    7 5
    1 2
    2 4
    2 7
    4 6
    3 5
    */
}
