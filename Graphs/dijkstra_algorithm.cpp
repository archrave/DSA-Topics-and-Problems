#include<bits/stdc++.h>
using namespace std;

// Considering an undirected graph:
/*
5 6
1 2 2
1 4 1
2 3 4
2 5 5
3 4 3
3 5 1
*/

vector<int> dijkstra(vector < pair<int, int >>  adj[], int n, int src = 1) {
    priority_queue < pair<int, int>, vector<pair<int, int>>, greater < pair<int, int>>> pq;
    vector<int> dist(n + 1, INT_MAX);

    dist[src] = 0;
    pq.push({ 0, src });
    while (!pq.empty()) {
        int node = pq.top().second;
        int distance = pq.top().first;
        pq.pop();

        // vector<pair<int, int>>::iterator it;
        for (auto it : adj[node]) {
            int next = it.first;
            int nextDist = it.second;
            if (dist[node] + nextDist < dist[next]) {
                dist[next] = dist[node] + nextDist;
                pq.push({ dist[next], next });
            }
        }
    }
    return dist;
}

void printGraph(vector<pair<int, int >> adj[], int n) {
    for (int i = 1; i <= n;i++) {
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
    vector<int> dist = dijkstra(adj, n);
    cout << "\nShortest paths: ";
    for (int i = 1; i < dist.size(); i++)
    {
        cout << dist[i] << " ";
    }
    return 0;
}

