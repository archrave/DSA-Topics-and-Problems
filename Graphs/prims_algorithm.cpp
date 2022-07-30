#include<bits/stdc++.h>
using namespace std;

// Considering an undirected graph:
/*
5 6
0 1 2
0 3 6
1 2 3
1 3 8
1 4 5
2 4 7
*/

// Used to find MST:
void prims(vector<pair<int, int>> adj[], int n) {

    vector<int> key(n, INT_MAX), parent(n, -1);
    vector<bool> mst(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    pq.push({ 0,0 });
    key[0] = 0;
    for (int i = 0; i < n - 1; i++) { //  No of edges should be n-1
        // mst[node] = true;
        int minm = INT_MAX;
        int u = pq.top().second;
        pq.pop();
        // Brute force approach
        /* for (int v = 0; v < n; v++)
            if (mst[v] == false && key[v] < minm)
                minm = key[v], u = v;
        */

        mst[u] = true;

        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mst[v] == false && weight < key[v]) {
                parent[v] = u;
                pq.push({ key[v], v });
                key[v] = weight;
            }
        }
    }
    cout << "\nMST:\n";
    for (int i = 1; i < n; i++)
        cout << parent[i] << " - " << i << " \n";
}

void printGraph(vector<pair<int, int >> adj[], int n) {
    for (int i = 0; i < n;i++) {
        cout << i << ": [ ";
        for (int j = 0; j < adj[i].size(); j++)
            cout << "{" << adj[i][j].first << ", " << adj[i][j].second << "} ";
        cout << "]\n";

    }
}

int main() {
    int n, m;
    cout << "\nEnter nodes and edges: ";
    cin >> n >> m;

    vector<pair<int, int>> adj[n + 1];
    cout << "\nEnter edges and weights with spaces: \n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v,w });
        adj[v].push_back({ u,w });
    }
    printGraph(adj, n);
    prims(adj, n);

    return 0;
}

