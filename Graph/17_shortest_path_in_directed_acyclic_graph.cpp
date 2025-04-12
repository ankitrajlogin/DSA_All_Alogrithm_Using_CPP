
// PROBLEM STATEMENT.
// Given a DAG comprising 𝑉  vertices and 𝐸  directed edges, where each edge ( 𝑢 , 𝑣 ) has an associated weight 𝑤 ( 𝑢 , 𝑣 ) , the task is to compute the shortest path from a designated source vertex 𝑠 to every other vertex in the graph. This entails finding paths such that the sum of the edge weights along each path is minimized.


// Approaches to Solve the Problem:

// 1. Dijkstra's Algorithm:

// Description: Dijkstra's algorithm is a classic method for finding the shortest paths from a single source vertex to all other vertices in a graph with non-negative edge weights. It utilizes a priority queue to greedily select the next vertex with the smallest tentative distance.​

// Limitations in the Context of DAGs:

// While Dijkstra's algorithm is effective for graphs with non-negative weights, it doesn't efficiently exploit the acyclic nature of DAGs.

// The algorithm's time complexity is 
// 𝑂 (( 𝑉 + 𝐸 ) log𝑉 ) , which, although efficient, isn't optimal for DAGs where a linear time solution exists.



// 2. Topological Sort-Based Approach:
// Description: This approach capitalizes on the acyclic nature of DAGs by first performing a topological sort of the vertices. In a topological order, for every directed edge 
// 𝑢 → 𝑣 , vertex 𝑢 precedes 𝑣 . This ordering ensures that each vertex is processed only after all its predecessors have been considered, facilitating efficient relaxation of edges.​

// Advantages:

// Efficiency: The combined process of topological sorting and shortest path computation runs in linear time, 
// 𝑂 ( 𝑉 + 𝐸 ) , making it optimal for DAGs.

// Simplicity: The method is straightforward and avoids the overhead of priority queues or multiple edge relaxations inherent in Dijkstra's and Bellman-Ford algorithms.



// Why Topological Sort?
// In a DAG, once we process a node in topological order, we are sure that all its predecessors have already been processed — this makes it ideal for dynamic programming-based shortest path algorithms.


#include<bits/stdc++.h>
using namespace std ; 

// ----------- Topological Sort Function -----------
void topoSort(int node , vector<bool>& visited , stack<int>& st , vector<pair<int,int>>adj[]){
    visited[node] = true ; 

    for(int i = 0 ; i< adj[node].size() ; i++){
        int neighbor = adj[node][i].first ; 

        if(!visited[neighbor]){
            topoSort(neighbor , visited , st , adj) ; 
        }
    }

    st.push(node) ; 
}


// ----------- Shortest Path in DAG Function -----------

vector<int>shortestPathDAG(int V , vector<pair<int,int>>adj[] , int source){
    vector<bool>visited(V , false) ; 
    stack<int>st ; 

    // Step 1: Perform Topological Sort
    for(int i = 0 ;i < V; i++){
        if(!visited[i]){
            topoSort(i , visited , st , adj) ; 
        }
    }

    // Step 2: Initialize distance array
    vector<int>dist(V , INT_MAX) ; 
    dist[source] = 0 ; 

    // Step 3: Process vertices in topological order
    while(!st.empty()){
        int u = st.top() ; 

        st.pop() ; 

        if(dist[u] != INT_MAX){
            for(int i = 0 ; i< adj[u].size() ; i++){
                int v = adj[u][i].first ; 
                int weight = adj[u][i].second ; 

                if(dist[u] + weight < dist[v]){
                    dist[v] = dist[u] + weight ; 
                }
            }
        }
    }

    return dist ; 

}

// 1. Topological Sort (DFS-based) :  O(V + E)
// 2.  Relaxing Edges in Topological Order : O(V + E)
// so , 
// overall time complexity : O(V+E) ; 

// Overall Space Complexity = O(V + E)

// ----------- Main Function with Input -----------
int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<pair<int, int>> adj[V];
    cout << "Enter each edge as: u v w (u -> v with weight w)\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    vector<int> distances = shortestPathDAG(V, adj, source);

    cout << "\nShortest distances from source " << source << ":\n";
    for (int i = 0; i < V; ++i) {
        if (distances[i] == numeric_limits<int>::max())
            cout << "Vertex " << i << ": INF\n";
        else
            cout << "Vertex " << i << ": " << distances[i] << "\n";
    }

    return 0;
}



// // INPUT 
// 6 7
// 0 1 2
// 0 4 1
// 1 2 3
// 4 2 2
// 2 3 6
// 4 5 4
// 5 3 1
// 0

// 0 → 1 (2)
// 0 → 4 (1)
// 1 → 2 (3)
// 4 → 2 (2)
// 2 → 3 (6)
// 4 → 5 (4)
// 5 → 3 (1)


// OUTPUT 
// Enter number of vertices and edges: 
// Enter each edge as: u v w (u -> v with weight w)
// Enter source vertex: 

// Shortest distances from source 0:
// Vertex 0: 0
// Vertex 1: 2
// Vertex 2: 3
// Vertex 3: 8
// Vertex 4: 1
// Vertex 5: 5


