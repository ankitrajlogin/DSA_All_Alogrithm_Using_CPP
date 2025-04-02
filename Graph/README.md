# Graphs in Data Structures and Algorithms (DSA)

---

## 1. What is a Graph?
**Definition**:  
A graph is a non-linear data structure consisting of **vertices (nodes)** and **edges** connecting these vertices. Formally, \( G = (V, E) \), where \( V \) is a set of vertices and \( E \) is a set of edges.

**Real-Life Example**:  
- Social networks (vertices = users, edges = friendships).  
- Transportation networks (vertices = cities, edges = roads/flights).

---

## 2. Types of Graphs

### a) Directed vs. Undirected
- **Undirected Graph**: Edges have no direction (e.g., Facebook friendships).  
- **Directed Graph (Digraph)**: Edges have direction (e.g., Twitter follows).  

### b) Weighted vs. Unweighted
- **Weighted Graph**: Edges have weights (e.g., road distances).  
- **Unweighted Graph**: All edges have equal weight.  

### c) Cyclic vs. Acyclic
- **Cyclic Graph**: Contains cycles (e.g., round-trip flights).  
- **Acyclic Graph**: No cycles (e.g., family trees).  

### d) Special Graphs
- **Tree**: Connected acyclic graph.  
- **Bipartite Graph**: Vertices divided into two disjoint sets (e.g., job applicants and jobs).  
- **Complete Graph**: Every pair of vertices is connected.  

---

## 3. Graph Representations

### a) Adjacency Matrix
- A 2D array where `matrix[i][j]` indicates an edge from \( i \) to \( j \).  
- **Time Complexity**:  
  - Check edge: \( O(1) \).  
  - Space: \( O(V^2) \).  

```cpp
int adjMatrix[5][5] = {0};
adjMatrix[0][1] = 1;  // Edge from 0 to 1 (unweighted)
adjMatrix[0][1] = 5;  // Edge from 0 to 1 (weighted) 
```

### b) Adjacency List
Array of linked lists/vectors storing neighbors.

**Time Complexity**:

- Check edge: O(V) 
- Space: O(V + E).

```cpp
// Unweighted adjacency list
vector<int> adjList[5];
adjList[0].push_back(1);  // Edge 0→1

// Weighted adjacency list
vector<pair<int, int>> weightedAdjList[5];
weightedAdjList[0].push_back({1, 5});  // Edge 0→1 with weight 5
```

### 4. Graph Traversal Algorithms

#### a) Breadth-First Search (BFS)
**Purpose**: Shortest path in unweighted graphs.

**Time Complexity**: O(V + E).

**Space Complexity**: O(V).

```cpp
#include <queue>
#include <vector>

void BFS(int start, vector<int> adj[], int V) {
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}
```

#### b) Depth-First Search (DFS)
**Purpose**: Cycle detection, topological sorting.

**Time Complexity**: O(V + E).

**Space Complexity**: O(V).

```cpp
#include <vector>

void DFS(int u, vector<int> adj[], vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            DFS(v, adj, visited);
        }
    }
}
```

### 5. Key Graph Algorithms

#### a) Shortest Path Algorithms

##### i) Dijkstra's Algorithm
**Purpose**: Shortest path in weighted graphs with non-negative weights.

**Time Complexity**: O((V + E) log V) (priority queue).

**Real-Life Use**: GPS navigation.

```cpp
#include <queue>
#include <vector>
using namespace std;

vector<int> dijkstra(vector<pair<int, int>> adj[], int V, int src) {
    vector<int> dist(V, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (auto &edge : adj[u]) {
            int v = edge.first, weight = edge.second;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
```

##### ii) Bellman-Ford Algorithm
**Purpose**: Handles graphs with negative weights (no negative cycles).

**Time Complexity**: O(V * E).

```cpp
vector<int> bellmanFord(vector<pair<int, int>> adj[], int V, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    for (int i = 0; i < V-1; i++) {
        for (int u = 0; u < V; u++) {
            for (auto &edge : adj[u]) {
                int v = edge.first, weight = edge.second;
                if (dist[u] != INT_MAX && dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }
    return dist;
}
```

##### iii) Floyd-Warshall Algorithm
**Purpose**: All-pairs shortest path.

**Time Complexity**: O(V^3).

```cpp
void floydWarshall(int graph[][V], int V) {
    int dist[V][V];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}
```

#### b) Minimum Spanning Tree (MST)

##### i) Kruskal's Algorithm
**Purpose**: Greedy algorithm to find MST.

**Time Complexity**: O(E log E).

```cpp
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

vector<Edge> kruskal(vector<Edge> edges, int V) {
    vector<Edge> result;
    sort(edges.begin(), edges.end());
    vector<int> parent(V);
    for (int i = 0; i < V; i++) parent[i] = i;

    for (Edge &e : edges) {
        if (find(parent, e.u) != find(parent, e.v)) {
            result.push_back(e);
            union(parent, e.u, e.v);
        }
    }
    return result;
}
```

##### ii) Prim's Algorithm
**Purpose**: Greedy algorithm to grow MST from a node.

**Time Complexity**: O(E log V).

```cpp
#include <queue>
#include <vector>
using namespace std;

vector<pair<int, int>> prim(vector<pair<int, int>> adj[], int V) {
    vector<bool> visited(V, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0}); // {weight, vertex}
    vector<pair<int, int>> mst;

    while (!pq.empty()) {
        auto [weight, u] = pq.top();
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        if (u != 0) mst.push_back({parent[u], u});
        for (auto &[v, w] : adj[u]) {
            if (!visited[v]) {
                pq.push({w, v});
                parent[v] = u;
            }
        }
    }
    return mst;
}
```

This markdown file contains the provided graph algorithms formatted properly with code snippets and descriptions.
