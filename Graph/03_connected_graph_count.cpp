#include<bits/stdc++.h>

using namespace std ; 

void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int countConnectedComponents(int n, vector<vector<int>> &adj) {
    vector<bool> visited(n, false);
    int components = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            components++;
            dfs(i, adj, visited);
        }
    }
    return components;
}


// Space Complexity: O(N + M) (Adjacency list storage + recursion stack)

// if the all edges are connected, hence then single dfs , all the node get visited , hence stack space is M . 


// Time Complexity: O(N + M) (N = nodes, M = edges)

int main() {
    int n, m;
    cin >> n >> m;

    // n --> number of nodes ; 
    // m --> number of edges ; 
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "Number of connected components: " << countConnectedComponents(n, adj) << endl;

    return 0;
}


