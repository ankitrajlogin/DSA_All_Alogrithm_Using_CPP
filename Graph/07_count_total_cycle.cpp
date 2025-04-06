#include <bits/stdc++.h>
using namespace std; 

// DFS function to count cycles
void countCyclesDFS(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited, int &cycleCount) {
    visited[node] = true;

    for (auto adjNode : adj[node]) {
        if (!visited[adjNode]) {
            countCyclesDFS(adjNode, node, adj, visited, cycleCount);
        }
        else if (adjNode != parent) { 
            cycleCount++; // Found a cycle
        }
    }
}

// Function to count total cycles in an undirected graph using DFS
int countTotalCycles(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    int cycleCount = 0;

    for (int startNode = 0; startNode < n; startNode++) {
        if (!visited[startNode]) {  
            countCyclesDFS(startNode, -1, adj, visited, cycleCount);
        }
    }
    
    return cycleCount / 2; // Each cycle is counted twice
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

    int totalCycles = countTotalCycles(adj);
    cout << "Total Cycles: " << totalCycles << endl;

    return 0;
}


// 0
// / \
// 1---2
// \ / \
//  3---4

// INPUT 

// 0 1
// 1 2
// 2 0
// 1 3
// 3 4
// 4 2
// 2 3


// Total Cycles: 3
