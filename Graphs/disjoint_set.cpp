#include<bits/stdc++.h>
using namespace std;


void makeSet(int n, int parent[], int rank[]) {
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

// This function gives the ultimate parent, so this should be used to find the parent of any node(not the parent array). 
void findPar(int node) {
    if (node == parent[node]) {
        return node;
    }
    // Path compression: 
    parent[node] = findPar(parent[node]);
    return parent[node];
}

void union(int u, int v, int rank[], int parent[]) {
    u = findPar(u);
    v = findPar(v);

    if (rank[u] == rank[v]) {
        parent[v] = u;
        rank[u]++;
    }
    else if (rank[u] < rank[v])
        parent[u] = v;
    else
        parent[v] = u;
}

int main()
{
    int parent[100000];
    int rank[100000];


    makeSet()
        return 0;
}