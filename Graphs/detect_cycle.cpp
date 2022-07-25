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
// DFS Solution:

bool detectHelper(vector<int> adj[], vector<int>& vis, int node, int parent) {
    for (auto it : adj[node]) {
        // cout << endl << node << " ; " << parent << " : it - " << it;
        if (!vis[it]) {
            vis[it] = 1;
            return detectHelper(adj, vis, it, node);
        }
        else if (parent != -1 && it != parent) {
            return true;
        }
    }
    return false;

}
bool detectCycleDFS(vector<int> adj[], int n) {

    vector<int> vis(n + 1, 0);
    // For traversing through all components:
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            if (detectHelper(adj, vis, i, -1))  return true;
        }
    }
    return false;
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
    // bfs(adj, n);
    // dfs(adj, n);
    printGraph(adj, n);
    string s = (detectCycle(adj, n)) ? "\nBFS true" : "\n BFS false";
    cout << endl << s;
    s = (detectCycleDFS(adj, n)) ? "\nDFS true" : "\nDFS false";
    cout << endl << s;
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
7 5
1 2
2 4
2 7
4 6
3 5
*/

/*
8 6
1 3
3 4
2 3
3 6
3 8
6 7
*/