
// Problem Statement
// You are in a city with n intersections numbered from 0 to n - 1, connected by bidirectional roads. Each road connects two intersections and takes a certain amount of time to traverse.​

// Given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] indicates a road between intersections ui and vi taking timei minutes, determine the number of different ways to travel from intersection 0 to intersection n - 1 in the shortest possible time.​
// Since the answer can be large, return it modulo 10⁹ + 7.​


// Intuition
// This problem is an extension of Dijkstra's algorithm. While Dijkstra's algorithm finds the shortest distances from the source to all other nodes, here we also need to count the number of shortest paths to each node.​

// To achieve this, we maintain two arrays:​

// dist[]: Stores the shortest distance from the source to each node.

// ways[]: Stores the number of shortest paths to each node.​

// While traversing the graph using Dijkstra's algorithm, we update these arrays as follows:​

// If a shorter path to a neighbor is found, update its distance and set its number of ways equal to the current node's number of ways.

// If another shortest path to a neighbor is found (i.e., equal distance), increment its number of ways by the current node's number of ways.



#include <bits/stdc++.h>
using namespace std;


int countPaths(int n, vector<vector<int>>& roads) {
    vector<vector<pair<int,int>>>adj(n) ; 

    for(auto it : roads){
        adj[it[0]].push_back({it[1] , it[2]}) ; 
        adj[it[1]].push_back({it[0] , it[2]}) ; 
    }

    priority_queue<pair<long long ,int> , vector<pair<long long,int>> , greater<pair<long long , int>>> pq ; 

    vector<long long>dist(n , LLONG_MAX) ; 

    vector<int>ways(n , 0) ; 

    dist[0] = 0 ; 
    ways[0] = 1 ; 

    pq.push({0 , 0}) ; 

    int mod = 1e9 + 7 ; 

    while(!pq.empty()){
        long long dis = pq.top().first ; 
        int node = pq.top().second ; 

        pq.pop() ; 

        for(auto it : adj[node]){
            int adjNode = it.first ; 
            long long edw = it.second ; 

            if(dis + edw < dist[adjNode]){
                dist[adjNode] = dis + edw ; 
                pq.push({dis + edw , adjNode}) ; 
                ways[adjNode] = ways[node] ;
            }
            else if(dis + edw == dist[adjNode]){
                ways[adjNode] = (ways[adjNode] + ways[node])%mod ; 
            }
        }
    }

    return ways[n-1]%mod ; 

}



int main() {
    int n = 7;
    vector<vector<int>> roads = {
        {0, 6, 7},
        {0, 1, 2},
        {1, 2, 3},
        {1, 3, 3},
        {6, 3, 3},
        {3, 5, 1},
        {6, 5, 1},
        {2, 5, 1},
        {0, 4, 5},
        {4, 6, 2}
    };

    

    int result = countPaths(n, roads);
    cout << "Number of ways to arrive at destination: " << result << endl;

    return 0;
}


// 📈 Complexity Analysis
// Time Complexity: O((V + E) log V), where V is the number of vertices and E is the number of edges. This is due to the priority queue operations in Dijkstra's algorithm.​
// HeyCoach Blog

// Space Complexity: O(V + E), for storing the adjacency list and auxiliary arrays.​