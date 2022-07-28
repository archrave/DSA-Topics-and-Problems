#include<bits/stdc++.h>
using namespace std;

/*
6 6
2 3 1
3 1 1
4 0 1
4 1 1
5 0 1
5 2 1
*/

/*
6 7
0 1 2
0 4 1
1 2 3
2 3 6
4 2 2
4 5 4
5 3 1

*/


//  Using a weighted DAG:

void dfsSort(vector<pair<int, int>> adj[], vector<int>& vis, stack<int>& st, int node) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it.first])
            dfsSort(adj, vis, st, it.first);
    }
    st.push(node);
}

vector<int> shortestPath(vector<pair<int, int>> adj[], int n, int src = 0) {

    stack<int> st;
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++) {
        if (!vis[i])
            dfsSort(adj, vis, st, i);
    }
    // cout << "\nTopo Sort: ";
    // while (!st.empty())
    // {
    //     cout << st.top() << " ";
    //     st.pop();
    // }
    fill(vis.begin(), vis.end(), INT_MAX);
    vis[src] = 0;
    while (!st.empty()) {
        int node = st.top();
        if (vis[node] != INT_MAX) {
            for (auto it : adj[node]) {
                if (vis[node] + it.second < vis[it.first])
                    vis[it.first] = vis[node] + it.second;
            }
            st.pop();
        }
    }
    return vis;
}

void printGraph(vector<pair<int, int>> adj[], int n) {
    for (int i = 0; i < n;i++) {
        cout << i << ": [";
        for (int j = 0; j < adj[i].size(); j++)
            cout << adj[i][j].first << " ";
        cout << "]\n";

    }
}

int main() {
    int  n, m;
    cout << "Enter nodes, edges and weights in order: \n";
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
    }

    vector<int> vis = shortestPath(adj, n);
    cout << "\n Answer: ";
    for (int i = 0; i < vis.size(); i++)
    {
        cout << vis[i] << " ";
    }
    return 0;
}