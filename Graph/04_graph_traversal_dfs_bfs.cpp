// Running DFS on the Graph → O(N + M)
// ------------------------------------

// - DFS visits each node once → O(N).
// - DFS explores all edges (adjacency list traversal) → O(M).
// - When a node u is visited, DFS iterates through all its neighbors (edges) using adj[u].
// - Since each edge is stored twice (once for each node), the total traversal is O(2M) = O(M).
// - Since DFS runs on each connected component, in the worst case, it covers all N nodes and M edges.
// - Thus, the total time complexity is O(N + M).



// DFS	
// Time complexity : O(V + E)	
// space complexity : O(V) (Recursion Stack + Visited Array)

// BFS	
// Time complexity : O(V + E)
// space compleixyt : O(V) (Queue + Visited Array)


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// DFS Helper Function
void dfsHelper(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &result) {
    visited[node] = true;
    result.push_back(node);

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfsHelper(neighbor, adj, visited, result);
        }
    }
}

// DFS Traversal Function
vector<int> dfsTraversal(int n, vector<vector<int>> &adj, int startNode) {
    vector<bool> visited(n, false);
    vector<int> result;
    dfsHelper(startNode, adj, visited, result);
    return result;
}

// BFS Traversal Function
vector<int> bfsTraversal(int n, vector<vector<int>> &adj, int startNode) {
    vector<bool> visited(n, false);
    vector<int> result;
    queue<int> q;

    q.push(startNode);
    visited[startNode] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    return result;
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

    int startNode;
    cout << "Enter start node for DFS and BFS: ";
    cin >> startNode;

    vector<int> dfsResult = dfsTraversal(n, adj, startNode);
    vector<int> bfsResult = bfsTraversal(n, adj, startNode);

    cout << "DFS Traversal: ";
    for (int node : dfsResult) {
        cout << node << " ";
    }
    cout << endl;

    cout << "BFS Traversal: ";
    for (int node : bfsResult) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}


// Key Differences:
// DFS explores depth first → can get stuck in deep paths.

// BFS explores level-wise → good for shortest path problems.
