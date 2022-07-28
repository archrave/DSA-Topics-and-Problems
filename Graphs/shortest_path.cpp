#include<bits/stdc++.h>
using namespace std;

// Connsidering an undirected graph:

vector<int> shortestDistance(vector<int> adj[], int n, int src = 0) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    queue<int> q;
    q.push(src);
    // for (int i = 0; i < n; i++) {
    while (!q.empty()) {
        int node = q.front();
        for (auto it : adj[node]) {
            if (dist[node] + 1 < dist[it]) {
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
        q.pop();
    }
    // }
    return dist;
}

void printGraph(vector<int> adj[], int n) {
    for (int i = 1; i <= n;i++) {
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
        adj[v].push_back(u);
    }
    printGraph(adj, n);
    vector<int> dist = shortestDistance(adj, n);
    cout << "\n Answer: ";
    for (int i = 0; i < dist.size(); i++)
    {
        cout << dist[i] << " ";
    }
    return 0;
}

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

9 11
0 1
0 3
1 2
1 3
2 6
3 4
4 5
5 6
6 7
6 8
7 8

*/