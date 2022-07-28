#include<bits/stdc++.h>
using namespace std;

/*

6 6
2 3
3 1
4 0
4 1
5 0
5 2

*/

// Using BFS: (Kahn's Algorithm)
// 2 1 1 1 0 0
// 0 1 2 3 4 5 
void topoSortBFS(vector<int> adj[], int n) {
    vector<int>  indegree(n, 0);
    for (int i = 0; i < n; i++) {
        for (auto it : adj[i]) {
            indegree[it]++;
        }
    }
    cout << "\nBFS Topo Sort: ";
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int node = q.front();
        cout << node << " ";
        for (auto it : adj[node]) {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
        q.pop();
    }
}

// Code is for a 0 indexed graph:
void sortDFS(vector<int> adj[], vector<int>& vis, stack<int>& st, int start) {
    vis[start] = 1;
    for (auto it : adj[start]) {
        if (!vis[it]) {
            sortDFS(adj, vis, st, it);
        }
    }
    st.push(start);
}
void topoSortDFS(vector<int> adj[], int n) {
    vector<int> vis(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        if (vis[i] == 0)
            sortDFS(adj, vis, st, i);
    }
    cout << "\nDFS Topo Sort: ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}
void printGraph(vector<int> adj[], int n) {
    for (int i = 0; i < n;i++) {
        cout << i << ": [";
        for (int j = 0; j < adj[i].size(); j++)
            cout << adj[i][j] << " ";
        cout << "]\n";

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
        // u -> v (Directed Graph)
    }
    printGraph(adj, n);
    topoSortDFS(adj, n);
    topoSortBFS(adj, n);
    return 0;
}




