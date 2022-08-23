#include<bits/stdc++.h>
using namespace std;


/*
5 5
1 2
2 3
2 4
3 1
4 5
*/

void printGraph(vector<int> adj[], int n) {
    for (int i = 1; i <= n;i++) {
        cout << i << ": [";
        for (int j = 0; j < adj[i].size(); j++)
            cout << adj[i][j] << " ";
        cout << "]\n";
    }
}

void toposort(vector<int> adj[], vector<int>& vis, stack<int>& st, int node) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (vis[it] == 0) {
            toposort(adj, vis, st, it);
        }
    }
    st.push(node);
}

void dfs(vector<int> tg[], vector<int>& vis, int node) {
    vis[node] = 1;
    cout << node << " ";
    for (auto it : tg[node]) {
        if (!vis[it])
            dfs(tg, vis, it);
    }
}
// Used to find strongly connected components in a graph.
void kosaraju(vector<int> adj[], int n) {


    // Toposort:
    stack<int> st;
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0)
            toposort(adj, vis, st, i);
    }

    // Creating a transpose graph:
    vector<int> tg[n + 1];
    for (int i = 1; i <= n; i++) {
        vis[i] = 0;
        for (auto it : adj[i]) {
            tg[it].push_back(i);
        }
    }

    // fill(vis.begin(), vis.end(), 0);         // No need since we're marking visited for all nodes as 0 above.

    // Running DFS in order of finishing time:
    cout << "\nStrongly connected components:\n";
    while (!st.empty()) {
        int node = st.top();
        if (!vis[node])
            dfs(tg, vis, node);
        cout << endl;
        st.pop();
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
    }

    // printGraph(adj, n);
    kosaraju(adj, n);

    return 0;
}

