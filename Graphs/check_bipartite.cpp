#include<bits/stdc++.h>
using namespace std;

bool biPartiteDFS(vector<int> adj[], int start, vector<int>& color) {

    for (auto it : adj[start]) {
        if (color[it] == -1) {
            color[it] = 1 - color[start];
            if (!biPartiteDFS(adj, it, color))   return false;
        }
        else if (color[it] == color[start])     return false;

    }
    return true;
}


bool checkBipartiteDFS(vector<int> adj[], int n) {

    vector<int> color(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        if (color[i] == -1)
        {
            color[i] = 0;
            if (!biPartiteDFS(adj, i, color))    return false;
        }
    }
    return true;
}

bool biPartiteBFS(vector<int> adj[], int start, vector<int>& color) {

    queue<int> q;
    q.push(start);
    color[start] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (color[it] == -1) {
                q.push(it);
                color[it] = 1 - color[node];
            }
            else if (color[it] == color[node]) {
                return false;
            }
        }
    }
    return true;
}
bool checkBipartite(vector<int> adj[], int n) {

    vector<int> color(n + 1, -1);
    for (int i = 1;i <= n; i++) {
        if (color[i] == -1) {
            color[i] = 0;
            if (!biPartiteBFS(adj, i, color))
                return false;

        }
    }
    return true;
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
    string s = (checkBipartite(adj, n)) ? "\nBFS Bipartite true" : "\nBFS Bipartite false";
    cout << endl << s;
    s = (checkBipartiteDFS(adj, n)) ? "\nDFS Bipartite true" : "\nDFS Bipartite false";
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
Not Bipartite:

7 7
1 2
2 4
2 7
7 6
3 5
4 3
6 3
*/

/*
Bipartite:

8 8
1 2
2 3
3 4
4 5
2 7
7 6
6 5
5 8
*/