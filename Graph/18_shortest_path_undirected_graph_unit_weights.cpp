
// ​To determine the shortest path in an undirected graph with unit weights, the Breadth-First Search (BFS) algorithm is particularly effective. In such graphs, each edge has an equal weight (typically 1), making BFS suitable because it explores all nodes at the present "depth" (distance from the source) before moving on to nodes at the next depth level. This ensures that the first time BFS reaches a node, it has found the shortest path to it.


#include <iostream>
#include <vector>
#include <queue>
#include <climits> // For INT_MAX

using namespace std;



// Function to perform BFS and find shortest paths from the source vertex
vector<int> shortestPathBFS(int src, int V, const vector<vector<int>>& adj) {
   
    vector<int> dist(V, INT_MAX);
    queue<int> q;

    dist[src] = 0;
    q.push(src);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

  
        for (int neighbor : adj[node]) {
            if (dist[node] + 1 < dist[neighbor]) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }
    return dist ;
}

// Time complexity :  0(V+E) as it is BFS 


int main() {
    int V = 6; // Number of vertices
    vector<vector<int>> adj(V);

    // Constructing the undirected graph
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0, 4};
    adj[3] = {1, 5};
    adj[4] = {1, 2, 5};
    adj[5] = {3, 4};

    int source = 0;
    vector<int>dist = shortestPathBFS(source, V, adj);


    cout << "Vertex\tShortest Distance from Source (" << source << ")\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t";
        if (dist[i] == INT_MAX) {
            cout << "INF\n";
        } else {
            cout << dist[i] << "\n";
        }
    }

    return 0;
}


// Alternative Approaches and Their Complexities:

// 1.  Dijkstra's Algorithm:
// Description: Dijkstra's algorithm finds the shortest paths from a single source vertex to all other vertices in a graph with non-negative edge weights. It uses a priority queue to greedily select the next vertex with the smallest tentative distance.​

// Time Complexity: When implemented with a binary heap, the time complexity is 𝑂((𝑉+𝐸)log⁡\𝑉), where 𝑉 is the number of vertices and E is the number of edges.​

// Space Complexity: Requires 𝑂(𝑉+𝐸) space to store the graph and additional data structures.​

// Why Not Used for Unit Weights: In graphs with unit weights, BFS is more efficient as it doesn't require the overhead of a priority queue. BFS achieves the same result in O(V+E) time, which is optimal for such cases.



// 2. Depth-First Search (DFS):
// Description: DFS explores as far along a branch as possible before backtracking. It's not inherently suited for finding shortest paths in unweighted graphs.​

// Time Complexity: O(V+E), similar to BFS.​
// Space Complexity: Can go up to O(V) in the worst case due to recursion stack.​

// Why Not Used: DFS doesn't guarantee finding the shortest path in unweighted graphs because it may explore longer paths before shorter ones.



// Conclusion:

// For undirected graphs with unit weights, BFS is the most efficient and straightforward algorithm to compute shortest paths. It operates with a time complexity of O(V+E) and a space complexity of O(V), making it optimal for this scenario. Alternative algorithms like Dijkstra's introduce unnecessary complexity and overhead without providing benefits in the context of unit weights.