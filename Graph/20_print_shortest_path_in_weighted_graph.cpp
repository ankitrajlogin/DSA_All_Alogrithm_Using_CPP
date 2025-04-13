// Problem Statement
// Given a weighted, undirected graph with V vertices and E edges, where each edge has a non-negative weight, determine the shortest path from a specified source vertex src to a destination vertex dest. If such a path exists, return the sequence of vertices representing this shortest path; otherwise, indicate that no path exists.


// Explanation
// Graph Representation: The graph is represented using an adjacency list, where each node maintains a list of its adjacent nodes along with the corresponding edge weights.​
// Distance Initialization: All node distances are initialized to infinity (INT_MAX), except for the source node, which is set to 0.​
// HeapSort Usage: A Heapsort is used to efficiently retrieve the node with the smallest tentative distance. This ensures that at each step, the node with the minimum distance is processed next.​
// Path Reconstruction: A parent array is maintained to reconstruct the shortest path from the source to the destination node after the algorithm completes.​
// Edge Relaxation: For each adjacent node, if a shorter path is found, the distance and parent are updated, and the node is reinserted into the set with the new distance.​


// Time and Space Complexity ; 
// Time Complexity: O(E log V)​
// Space Complexity: O(V + E)​

#include<bits/stdc++.h>

using namespace std ; 

vector<int>shortestPath(int V , vector<vector<int>>& edges , int src , int distination){

    vector<pair<int,int>>adj[V+1] ;

    for(auto it : edges){
        adj[it[0]].push_back({it[1] , it[2]}) ; 
        adj[it[1]].push_back({it[0] , it[2]}) ; 
    }

    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>pq ; 

    vector<int>dist(V + 1 , 1e9) ; 
    vector<int>parent(V+1) ; 

    for(int i = 1 ; i<=V  ; i++){
        parent[i] = i ; 
    }

    dist[src] = 0 ; 
    pq.push({0, src}) ; 

    while(!pq.empty()){
        auto it = pq.top() ; 
        pq.pop() ; 
        int node = it.second ; 
        int dis = it.first ; 

        if(dis > dist[node]){
            continue ;  
        }

        for(auto it : adj[node]){
            int adjNode = it.first ; 
            int edW = it.second ; 

            if(dis + edW < dist[adjNode]){
                dist[adjNode] = dis + edW ; 
                pq.push({dis +edW , adjNode}) ; 

                parent[adjNode] = node ; 
            }
        }
    }

    if(dist[distination] == 1e9){
        return {-1}  ; 
    }

    vector<int>path ; 
    int node = distination ; 


    while(parent[node] != node){
        path.push_back(node) ; 
        node = parent[node] ;
    }

    path.push_back(node) ; 

    reverse(path.begin() , path.end()) ; 

    return path ; 

}



int main() {
    int V = 5;
    vector<vector<int>> edges = {
        {1, 2, 2},
        {1, 3, 4},
        {2, 3, 1},
        {2, 4, 7},
        {3, 5, 3},
        {4, 5, 1}
    };
    int src = 1, dest = 5;

    vector<int> path = shortestPath(V, edges, src, dest);

    if (path.size() == 1 && path[0] == -1) {
        cout << "No path exists from " << src << " to " << dest << ".\n";
    } else {
        cout << "Shortest path from " << src << " to " << dest << ": ";
        for (int node : path) cout << node << " ";
        cout << "\n";
    }
    return 0;
}


// Shortest path from 1 to 5: 1 2 3 5

// Notes
// This implementation assumes that the graph is undirected and has non-negative edge weights.​

// If the graph contains negative edge weights, Dijkstra's algorithm may not produce correct results. In such cases, consider using the Bellman-Ford algorithm.​