#include <iostream>
#include <vector>

using namespace std;


// Space complexity = O(2xE)
vector<vector<int>> adjacencyList(int n, int m) {
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return adj;
}


// Space complexity = O(E)
vector<vector<int>> adjacencyMatrix(int n, int m) {
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1; // Remove this for directed graph
    }
    return adj;
}


// weighted graph representation 

vector<vector<pair<int, int>>> weightedAdjacencyList(int n, int m) {
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    return adj;
}




int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adjList = adjacencyList(n, m);
    vector<vector<int>> adjMatrix = adjacencyMatrix(n, m);
    vector<vector<pair<int, int>>> weightedAdjList = weightedAdjacencyList(n, m);
    
    return 0;
}
