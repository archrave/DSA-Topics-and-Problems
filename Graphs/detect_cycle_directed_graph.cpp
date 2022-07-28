#include<bits/stdc++.h>
using namespace std;


// Using Kahn's algorithm. We try to generate a topological sort.
// If we're unable to generate a topo-sort with N nodes, we declare that there exists a cycle.

bool detectCycleBFS(vector<int> adj[], int n) {

    vector<int> indegree(n + 1, 0);
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        for (auto it : adj[i])
            indegree[it]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    int cnt = 0;
    // cout << endl;
    while (!q.empty()) {
        int node = q.front();
        cnt++;
        // cout << "node: " << node << " ; cnt: " << cnt << endl;
        q.pop();
        for (auto it : adj[node]) {
            indegree[it]--;
            if (indegree[it] == 0)   q.push(it);
        }
    }
    // cout << "\ncnt: " << cnt << endl;
    if (cnt == n)    return false;
    else    return true;

}
bool cycleDFS(vector<int> adj[], vector<int>& vis, vector<int>& dfsVis, int node) {
    for (auto it : adj[node]) {
        if (!vis[it]) {
            vis[it] = 1;
            dfsVis[it] = 1;
            if (!cycleDFS(adj, vis, dfsVis, it))
                dfsVis[it] = 0;
            else
                return true;
        }
        else if (dfsVis[it] == 1) {
            return true;
        }
    }
    dfsVis[node] = 0;
    return false;
}
bool detectCycleDFS(vector<int> adj[], int n) {

    vector<int> vis(n + 1, 0), dfsVis(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            vis[i] = 1;
            dfsVis[i] = 1;
            if (cycleDFS(adj, vis, dfsVis, i))  return true;
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
        // u -> v (Directed Graph)
    }

    printGraph(adj, n);
    string s;
    s = (detectCycleBFS(adj, n)) ? "\nBFS Cycle true" : "\nBFS Cycle false";
    cout << endl << s;
    s = (detectCycleDFS(adj, n)) ? "\nDFS Cycle true" : "\nDFS Cycle false";
    cout << endl << s;

    return 0;
}

/*

9 10
1 2
2 3
3 4
4 5
5 6
3 6
7 2
7 8
8 9
9 7
*/

/*

No Cycle:

9 9
1 2
2 3
3 4
4 5
5 6
3 6
7 2
7 8
8 9

*/

