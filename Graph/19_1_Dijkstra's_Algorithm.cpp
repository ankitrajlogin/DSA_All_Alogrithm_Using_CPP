// ​Dijkstra's algorithm is a fundamental algorithm in computer science used to find the shortest paths from a single source vertex to all other vertices in a weighted graph with non-negative edge weights. It is widely applied in network routing protocols, geographical mapping, and various optimization problems.


// How Dijkstra's Algorithm Works
// The algorithm maintains a set of vertices whose shortest distance from the source is already known and repeatedly selects the vertex with the minimum tentative distance, updating the distances of its adjacent vertices.​

// Algorithm Steps:

// Initialization:
//     Set the distance to the source vertex as 0 and to all other vertices as infinity.​
//     Use a priority queue to store vertices based on their tentative distances.​

// Processing:
// While the priority queue is not empty:​
//     Extract the vertex with the minimum distance.
//     For each adjacent vertex, calculate the new tentative distance. If it's smaller than the previously known distance, update it and add the vertex to the priority queue.

// Termination:
//     Repeat the process until all vertices have been processed.​


// Time complexity : O(E*logV)
// space complexity : O(V + E) ; 

#include<bits/stdc++.h>

using namespace std ; 

vector<int>dijkstra(int V , vector<vector<pair<int,int>>>&adj , int src){
    vector<int>dist(V , INT_MAX) ; 

    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq ; 

    dist[src] = 0 ; 

    pq.push({0 , src}) ; 

    while(!pq.empty()){
        int u_dist = pq.top().first ; 
        int u = pq.top().second ; 

        pq.pop() ; 

        if(u_dist > dist[u]) continue ; 

        for(auto& edge : adj[u]){
            int v = edge.first ; 
            int weight = edge.second ; 

            if(dist[u] + weight < dist[v]){
                dist[v] = dist[u] + weight ; 
                pq.push({dist[v] , v}) ; 
            }
        }
    }

    return dist ; 
}



int main() {
    int V = 5;
    vector<vector<pair<int,int>>> adj(V);

    // Constructing the graph
    adj[0].push_back({1, 10});
    adj[0].push_back({4, 5});
    adj[1].push_back({2, 1});
    adj[1].push_back({4, 2});
    adj[2].push_back({3, 4});
    adj[3].push_back({0, 7});
    adj[3].push_back({2, 6});
    adj[4].push_back({1, 3});
    adj[4].push_back({2, 9});
    adj[4].push_back({3, 2});

    int source = 0;
    vector<int>dist = dijkstra(V, adj, source);

    cout << "Vertex\tDistance from Source " << source << "\n";
    for (int i = 0; i < V; ++i) {
        if (dist[i] == INT_MAX)
            cout << i << "\tINF\n";
        else
            cout << i << "\t" << dist[i] << "\n";
    }

    return 0;
}