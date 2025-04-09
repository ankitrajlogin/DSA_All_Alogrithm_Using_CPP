
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




