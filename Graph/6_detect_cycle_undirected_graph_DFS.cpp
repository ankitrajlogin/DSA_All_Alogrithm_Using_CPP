

#include <bits/stdc++.h>
using namespace std; 


// time complexity : O(N +M ) ; 
// space complexity ; O(N) (recursin stack + visited array) ; 


// DFS function to detect cycle
bool detectDFS(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;

    for (auto adjNode : adj[node]) {
        if (!visited[adjNode]) {
            if (detectDFS(adjNode, node, adj, visited)) return true;
        }
        else if (adjNode != parent) { 
            return true; // Cycle detected
        }
    }
    return false;
}

// Function to check cycle in an undirected graph using DFS
bool detectCycleDFS(vector<vector<int>>& adj) {
    int n = adj.size(); 
    vector<bool> visited(n, false);

    for (int startNode = 0; startNode < n; startNode++) {
        if (!visited[startNode]) {  
            if (detectDFS(startNode, -1, adj, visited)) return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> adj(n);
    cout << "Enter " << m << " edges (0-based indexing):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }

    if (detectCycleDFS(adj)) {
        cout << "Cycle Detected\n";
    } else {
        cout << "No Cycle\n";
    }

    return 0;
}
