
//  Problem Statement: Cheapest Flights Within K Stops
// Given a set of flights represented as edges in a directed, weighted graph, where each flight is defined by a starting city, a destination city, and a cost, determine the cheapest price from a source city to a destination city with at most k stops. If such a route doesn't exist, return -1

// #include<bits/stdc++.h>

// using namespace std ; 

// int cheapestFlight(int V , vector<vector<int>>&flights , int src , int dst , int k){
//     vector<pair<int,int>>adj[V] ;

//     for(auto it : flights){
//         adj[it[0]].push_back({it[1] , it[2]}) ;
//     }

//     priority_queue<pair<int,pair<int,int>> ,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq; // {dist , {node , stops}} ; 

//     pq.push({0 , {src , 0}}) ; 

//     vector<int>dist(V , 1e9) ; 
//     dist[src] = 0 ; 


//     while(!pq.empty()){
//         auto it = pq.top() ; 
//         pq.pop() ; 

//         int cost = it.first ; 
//         int node = it.second.first ; 
//         int stops = it.second.second ; 

//         cout << "value of this is : " << node << " " << stops << " " << cost << endl; 

//         if(stops > k){
//             continue ; 
//         }

       

//         for(auto iter : adj[node]){
//             int adjNode = iter.first ; 
//             int edw = iter.second ; 

//             if(cost + edw < dist[adjNode] && stops <= k){
//                 dist[adjNode] = cost + edw ; 
//                 pq.push({cost+edw , {adjNode , stops +1}}) ; 
//             }
//         }
//     }

//     return dist[dst] ; 
// }
// int main() {
//     int V = 6;
//     vector<vector<int>> flights = {
//         {0, 1, 2},
//         {0, 2, 4},
//         {1, 2, 1},
//         {1, 3, 7},
//         {2, 4, 3},
//         {3, 5, 1},
//         {4, 5, 1}
//     };
//     int src = 0, dst = 5, k = 2;

//     int cost = cheapestFlight(V, flights, src, dst, k);

//     if (cost == -1) {
//         cout << "No path exists from " << src << " to " << dst << " within " << k << " stops.\n";
//     } else {
//         cout << "Cheapest cost from " << src << " to " << dst << " within " << k << " stops: " << cost << "\n";
//     }

//     return 0;
// }

// value of this is : 0 0 0
// value of this is : 1 1 2
// value of this is : 2 2 3
// value of this is : 2 1 4
// value of this is : 4 3 6
// value of this is : 3 2 9
// value of this is : 0 0 0
// value of this is : 1 1 2
// value of this is : 2 2 3
// value of this is : 2 1 4
// value of this is : 4 3 6
// value of this is : 3 2 9
// value of this is : 1 1 2
// value of this is : 2 2 3
// value of this is : 2 1 4
// value of this is : 4 3 6
// value of this is : 3 2 9
// value of this is : 4 3 6
// value of this is : 3 2 9
// value of this is : 3 2 9
// value of this is : 5 3 10
// Cheapest cost from 0 to 5 within 2 stops: 10




/***************************************************/
// Above solution is wrong because , Dijkstra's algorithm may prematurely discard paths that are more expensive initially but have the potential to lead to cheaper overall costs within the allowed number of stops. This is because Dijkstra's algorithm prioritizes nodes based solely on the current lowest cost, without accounting for the number of stops taken to reach that node. As a result, it might overlook paths that, while initially more expensive, could lead to a cheaper destination cost within the stop constraint.




// Correct Approach: Modified Dijkstra's Algorithm with Stop Tracking
// To address this issue, we can modify Dijkstra's algorithm to account for the number of stops. This involves tracking both the cost and the number of stops taken to reach each node. By doing so, we can ensure that we explore all viable paths within the allowed number of stops, even if they are not the cheapest initially.



// Intuition
// By tracking both the cost and the number of stops to reach each node, we ensure that we consider all viable paths within the allowed number of stops. This approach allows us to find the cheapest path that satisfies the stop constraint, even if it involves initially more expensive routes.​


#include <bits/stdc++.h>
using namespace std;

int cheapestFlight(int V, vector<vector<int>>& flights, int src, int dst, int k) {
    // Build the adjacency list
    vector<vector<pair<int, int>>> adj(V);
    for (auto& flight : flights) {
        int u = flight[0], v = flight[1], w = flight[2];
        adj[u].emplace_back(v, w);
    }

    // Priority queue: {cost, {node, stops}}
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    pq.emplace(0, make_pair(src, 0));

    // Distance array to track the minimum cost to reach each node with a certain number of stops
    vector<vector<int>> dist(V, vector<int>(k + 2, INT_MAX));
    dist[src][0] = 0;

    while (!pq.empty()) {
        auto iterator = pq.top();
        pq.pop();
        int cost = iterator.first;
        int node = iterator.second.first;
        int stops = iterator.second.second;

        if (node == dst) return cost;
        if (stops > k) continue;

        for (auto iter : adj[node]) {
            int adjNode = iter.first ; 
            int weight = iter.second ; 
            int newCost = cost + weight;
            if (newCost < dist[adjNode][stops + 1]) {
                dist[adjNode][stops + 1] = newCost;
                pq.emplace(newCost, make_pair(adjNode, stops + 1));
            }
        }
    }

    return -1;
}

int main() {
    int V = 6;
    vector<vector<int>> flights = {
        {0, 1, 2},
        {0, 2, 4},
        {1, 2, 1},
        {1, 3, 7},
        {2, 4, 3},
        {3, 5, 1},
        {4, 5, 1}
    };
    int src = 0, dst = 5, k = 2;

    int cost = cheapestFlight(V, flights, src, dst, k);

    if (cost == -1) {
        cout << "No path exists from " << src << " to " << dst << " within " << k << " stops.\n";
    } else {
        cout << "Cheapest cost from " << src << " to " << dst << " within " << k << " stops: " << cost << "\n";
    }

    return 0;
}


// Time and Space Complexity:

// Time Complexity: O((V + E) * k), where V is the number of vertices, E is the number of edges, and k is the maximum number of stops. Each node can be visited up to k times with different numbers of stops.​

// Space Complexity: O(V * k), due to the distance array that stores the minimum cost for each node with up to k stops.




