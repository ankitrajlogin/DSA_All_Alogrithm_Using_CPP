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


b) Adjacency List
Array of linked lists/vectors storing neighbors.

Time Complexity:

Check edge: O ( V ) 
Space: O ( V + E ) O(V+E).


```cpp

// Unweighted adjacency list
vector<int> adjList[5];
adjList[0].push_back(1);  // Edge 0→1

// Weighted adjacency list
vector<pair<int, int>> weightedAdjList[5];
weightedAdjList[0].push_back({1, 5});  // Edge 0→1 with weight 5

```