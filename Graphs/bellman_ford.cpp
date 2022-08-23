#include<bits/stdc++.h>
using namespace std;

/*
6 7
0 1 5
1 2 -2
1 5 -3
2 4 3
3 2 6
3 4 -2
5 3 1
*/

struct node
{
    int u;
    int v;
    int wt;
    node(int first, int second, int weight) {
        u = first, v = second, wt = weight;
    }
};

void bellmanFord(vector<node>& edges, int n, int src = 0) {

    vector<int> dist(n + 1, 10000000);
    dist[src] = 0;
    for (int i = 1; i < n; i++) {                           // N - 1 times.
        for (auto it : edges) {
            int u = it.u, v = it.v, wt = it.wt;
            if (dist[u] + wt < dist[v])
                dist[v] = dist[u] + wt;
        }
    }
    for (auto it : edges) {
        int u = it.u, v = it.v, wt = it.wt;
        if (dist[u] + wt < dist[v]) {
            cout << "\n\nNegative Cycle!\n\n" << endl;
            return;
        }
    }
    cout << "\nShortest distances:\n";
    for (int i = 0; i < n; i++) {
        cout << i << ": " << dist[i] << endl;
    }

}

void printGraph(vector<pair<int, int >> adj[], int n) {
    cout << endl;
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
    vector<node> edges;                         // A list of edges and weights:
    cout << "\nEnter edges with spaces: \n";
    for (int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({ v,wt });
        edges.push_back(node(u, v, wt));
    }
    printGraph(adj, n);
    bellmanFord(edges, n);
    return 0;
}
