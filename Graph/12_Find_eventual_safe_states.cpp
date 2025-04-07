

// Problem Statement:

// Given a directed graph represented as an adjacency list, we need to determine all the nodes that are eventual safe nodes. A node is considered safe if every possible path starting from that node leads to a terminal node. A terminal node is a node with no outgoing edges.​

// Key Concepts:
// Terminal Nodes: Nodes with no outgoing edges. These nodes are inherently safe since there are no further paths to traverse.​

// Safe Nodes: Nodes from which all possible paths eventually lead to terminal nodes. If a node leads to a cycle or has a path that leads to a cycle, it is not considered safe.​

// Cycles in Graphs: Nodes that are part of cycles or have paths leading to cycles cannot be safe, as they do not guarantee termination at a terminal node.



// Steps:
// Initialize State Tracking Arrays:
// visited: To track if a node has been visited during DFS.​
// pathVisited: To track nodes in the current DFS path, aiding in cycle detection.​
// safe: To mark nodes as safe or unsafe based on DFS exploration.​
// DEV Community
// DFS Traversal with Cycle Detection:
// For each unvisited node, perform a DFS.​
// Mark the node as visited and add it to the current path.​

// Explore all adjacent nodes:
// If an adjacent node is unvisited, recursively perform DFS on it.
// If an adjacent node is already in the current path (pathVisited), a cycle is detected, and the node is marked as unsafe.
// After exploring all adjacent nodes, remove the node from the current path.​
// If no cycles are detected, mark the node as safe.​


// Collect Safe Nodes:
// After processing all nodes, collect and return all nodes marked as safe.​

// Complexity Analysis:
// Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges. Each node and edge is processed once during the DFS traversal.​

// Space Complexity: O(V) for the state tracking arrays and the recursion stack in the worst case.



#include <iostream>
#include <vector>

using namespace std;

bool dfsCheck(int node, const vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis, vector<int>& check) {
    vis[node] = 1;
    pathVis[node] = 1;
    check[node] = 0;

    for (auto it : adj[node]) {
        if (!vis[it]) {
            if (dfsCheck(it, adj, vis, pathVis, check)) {
                check[node] = 0;
                return true;
            }
        } else if (pathVis[it]) {
            check[node] = 0;
            return true;
        }
    }

    check[node] = 1;
    pathVis[node] = 0;
    return false;
}

vector<int> eventualSafeNodes(int V, const vector<vector<int>>& adj) {
    vector<int> vis(V, 0);
    vector<int> pathVis(V, 0);
    vector<int> check(V, 0);
    vector<int> safeNodes;

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfsCheck(i, adj, vis, pathVis, check);
        }
    }

    for (int i = 0; i < V; i++) {
        if (check[i] == 1) {
            safeNodes.push_back(i);
        }
    }

    return safeNodes;
}

int main() {
    vector<vector<int>> graph = {
        {1, 2},
        {2, 3},
        {5},
        {0},
        {5},
        {},
        {}
    };

    int V = graph.size();
    vector<int> safeNodes = eventualSafeNodes(V, graph);

    cout << "Safe nodes are: ";
    for (int node : safeNodes) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}



// 0 → 1 → 2 → 5
// ↑   ↓   ↑
// |   3   4
// |       |
// +-------+


// Safe nodes are: 2 4 5 6

