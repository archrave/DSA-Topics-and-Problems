#include<bits/stdc++.h>
using namespace std;
/*
6 9
1 4 1
1 2 2
2 3 3
2 4 3
1 5 4
3 4 5
2 6 7
3 6 8
4 5 9

*/

struct node {
    int u;
    int v;
    int w;
};

bool comp(node x, node y) {
    if (x.w < y.w)   return true;
    else return false;
}

// This function gives the ultimate parent, so this should be used to find the parent of any node(not the parent array). 
int findPar(int node, vector<int>& parent) {
    if (node == parent[node])
        return node;

    // Path compression: 
    parent[node] = findPar(parent[node], parent);
    return parent[node];
}

void unionn(int u, int v, vector<int>& rank, vector<int>& parent) {
    u = findPar(u, parent);
    v = findPar(v, parent);

    if (rank[u] == rank[v]) {
        parent[v] = u;
        rank[u]++;
    }
    else if (rank[u] < rank[v])
        parent[u] = v;
    else
        parent[v] = u;
}


void kruskal(vector<node>& g, int n, int m) {

    // For disjoint set
    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0);

    vector<pair<int, int>> mst;

    int mstCost = 0;

    // Sorting according to the weight
    sort(g.begin(), g.end(), comp);
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    for (int i = 0; i < m; i++) {
        int u = g[i].u, v = g[i].v, w = g[i].w;
        if (findPar(u, parent) != findPar(v, parent)) {
            mstCost += w;
            unionn(u, v, rank, parent);
            mst.push_back({ u, v });
        }
    }
    cout << "\n\nMST:\n";
    for (int i = 0; i < mst.size(); i++) {
        cout << mst[i].first << " - " << mst[i].second << endl;
    }
    cout << "\nMST Cost: " << mstCost;
}



int main()
{
    int n, m;
    cout << "Enter nodes and edges: ";
    cin >> n >> m;

    vector<node> g;
    cout << "\nEnter u, v and w in order:\n ";

    // Input not taken in an adjacency list, but as a list of edges and weights.
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        node n;                                         //{u, v, w}
        n.u = u, n.v = v, n.w = w;
        g.push_back(n);
    }

    kruskal(g, n, m);
    return 0;
}