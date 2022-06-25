#include<iostream>
#include<vector>
#include<queue>
using namespace std;


// DFS print
void printGraphDFS(vector<vector<int>> v, vector<bool>& visited, int sv) {
    cout << sv << endl;
    visited[sv] = true;
    for (int i = 0; i < v.size(); i++) {
        if (v[sv][i] == 1 && !visited[i]) {
            printGraphDFS(v, visited, i);
        }
    }
}

//BFS Traversal
void printGraphBFS(vector<vector<int>> v, vector<bool>& visited, int sv) {
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    cout << endl;
    while (!q.empty()) {
        int curr = q.front();
        cout << curr << " ";
        for (int i = 0; i < v.size(); i++) {
            if (v[curr][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
        q.pop();
    }
    cout << endl;
}

void disconnectedDFS(vector<vector<int>> v) {
    int n = v.size();
    vector<bool> visited(n, false);
    for (int i = 0; i < visited.size(); i++) {
        if (!visited[i]) {
            printGraphDFS(v, visited, i);
        }
    }
}


int dfs(vector<vector<int>> v, vector<bool>& visited, int sv) {

    visited[sv] = true;
    for (int i = 0; i < v.size(); i++) {
        if (!visited[i] && v[sv][i] == 1)
            dfs(v, visited, i);
    }

}
/* ****************** Problems ****************** */



int connectedComponents(vector<vector<int>> v) {
    int n = v.size(), count = 0;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(v, visited, i);
            count++;
        }
    }
    return count;
}

int main() {
    int n, e;
    cout << "Enter Graph: \n";
    cin >> n >> e;
    // Declaring and initialising our adjacency matrix: 
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    vector<bool> visited(n, false);
    for (int i = 0; i < e; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        matrix[v1][v2] = 1;
        matrix[v2][v1] = 1;
    }
    cout << "DFS: \n";
    printGraphDFS(matrix, visited, 0);
    visited.clear();
    visited.resize(n, false);
    cout << endl << endl;
    cout << "DFS disconnected: \n";
    disconnectedDFS(matrix);
    cout << endl << endl;
    cout << "No. of connected Components: " << connectedComponents(matrix);
    // cout << "BFS: ";
    // printGraphBFS(matrix, visited, 0);

    /*
4
3
0 2
2 1
1 3
    */

    /*
7
8
0 1
0 2
1 3
1 4
2 6
3 5
4 5
5 6
    */

    /*
7
7
0 1
1 6
1 3
6 3
2 4
2 5
4 5
    */
    /*
11
6
0 1
3 4
4 5
2 6
6 7
8 9
    */

    return 0;
}