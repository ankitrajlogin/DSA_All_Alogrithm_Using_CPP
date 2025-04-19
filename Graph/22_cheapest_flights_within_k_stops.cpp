

// Another Method ::

// if we store the elements in the priority queue with the priority given to the minimum distance first, then after a few iterations we would realize that the Algorithm will halt when the number of stops would exceed. This may result in a wrong answer as it would not allow us to explore those paths which have more cost but fewer stops than the current answer.

// Also, a point to note here is that do we really need a priority queue for carrying out the algorithm? The answer for that is No because when we are storing everything in terms of a number of stops, the stops are increasing monotonically which means that the number of sops is increasing by 1 and when we pop an element out of the queue, we are always popping the element with a lesser number of stops first. Replacing the priority queue with a simple queue will let us eliminate an extra log(N) of the complexity of insertion-deletion in a priority queue which would in turn make our algorithm a lot faster.

// Approach:

// Initial configuration:

// Queue: Define a Queue that would contain pairs of the type {stops, {node,dist} }, where ‘dist’ indicates the currently updated value of the distance from the source to the ‘node’ and ‘stops’ contains the number of nodes one has to traverse in order to reach node from src.
// Distance Array: Define a distance array that would contain the minimum cost/distance from the source cell to a particular cell. If a cell is marked as ‘infinity’ then it is treated as unreachable/unvisited.
// Source and Destination: Define the source and the destination from where the flights have to run.
// The Algorithm consists of the following steps :

// Start by creating an adjacency list, a queue that stores the distance-node and stops pairs in the form {stops,{node,dist}} and a dist array with each node initialized with a very large number ( to indicate that they’re unvisited initially) and the source node marked as ‘0’.
// We push the source cell to the queue along with its distance which is also 0 and the stops are marked as ‘0’ initially because we’ve just started.
// Pop the element at the front of the queue and look out for its adjacent nodes. 
// If the current dist value of a node is better than the previous distance indicated by the distance array and the number of stops until now is less than K, we update the distance in the array and push it to the queue. Also, increase the stop count by 1.
// We repeat the above three steps until the queue becomes empty. Note that we do not stop the algorithm from just reaching the destination node as it may give incorrect results.
// Return the calculated distance/cost after we reach the required number of stops. If the queue becomes empty and we don’t encounter the destination node, return ‘-1’ indicating there’s no path from source to destination.


#include<bits/stdc++.h>
using namespace std ; 

int cheapestFlight(int V , vector<vector<int>> & flights , int src , int dst , int k){
    vector<pair<int,int>>adj[V] ;

    for(auto it : flights){
        adj[it[0]].push_back({it[1] , it[2]}) ;
    }

    queue<pair<int,pair<int,int>>>q ; 

    q.push({0, {src , 0}}) ;

    vector<int>dist(V , 1e9) ; 

    dist[src] = 0 ; 

    while(!q.empty()){
        auto it = q.front() ; 
        q.pop() ; 

        int stops = it.first ; 
        int node = it.second.first ; 
        int cost = it.second.second ; 

        if(stops > k){
            continue ; 
        }

        for(auto iter : adj[node]){
            int adjNode = iter.first ; 
            int edW = iter.second ; 

            if(cost + edW < dist[adjNode] && stops <= k){
                dist[adjNode] = cost + edW ; 
                q.push({stops+1 , {adjNode , cost + edW}}) ;
            }
        }
    }

    if(dist[dst] == 1e9){
        return -1 ; 
    }

    return dist[dst] ;
}



int main()
{
    // Driver Code.
    int n = 4, src = 0, dst = 3, K = 1;

    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600},
    {2, 3, 200}};

    int ans = cheapestFlight(n, flights, src, dst, K);

    cout << ans;
    cout << endl;

    cout << "Cheapest cost from " << src << " to " << dst << " within " << K << " stops: " << ans << "\n";

    cout << "----------------------------------------" << endl; 


    int V2 = 6;
    vector<vector<int>> flights2 = {
        {0, 1, 2},
        {0, 2, 4},
        {1, 2, 1},
        {1, 3, 7},
        {2, 4, 3},
        {3, 5, 1},
        {4, 5, 1}
    };
    int src2 = 0, dst2 = 5, k2 = 2;

    int cost2 = cheapestFlight(V2, flights2, src2, dst2, k2);

    if (cost2 == -1) {
        cout << "No path exists from " << src2 << " to " << dst2 << " within " << k2 << " stops.\n";
    } else {
        cout << "Cheapest cost from " << src << " to " << dst << " within " << k2 << " stops: " << cost2 << "\n";
    }

    return 0;
}




