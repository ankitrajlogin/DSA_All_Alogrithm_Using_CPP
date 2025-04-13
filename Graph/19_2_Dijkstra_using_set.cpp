
// Dijkstra's Algorithm Using std::set
// Key Characteristics:

// Structure: Utilizes a std::set to store pairs of (distance, node), automatically sorted by distance.​

// Duplicate Handling: Allows for efficient removal of outdated entries, ensuring that only the most recent shortest distances are considered.​

// Operations:
// Insertion: O(log V)​
// Deletion: O(log V)​
// Search: O(log V)​ 


// Advantages:
// Efficiently removes outdated entries, preventing unnecessary processing.​
// Maintains a clean set of current shortest distances.​

// Disadvantages:
// Slightly higher overhead due to the need for explicit deletion of outdated entries.​
// Overall time complexity remains O((V + E) log V).​ (but little better than heap sort) 


// Time and Space Complexity Comparison

// std::priority_queue	 :  O((V + E) log V)	 and O(V)	
// std::set	            O((V + E) log V)	 and O(V)	



#include<bits/stdc++.h>

using namespace std ; 

vector<int> dijkstra(int src ,const vector<vector<pair<int,int>>>& adjList){
    int numVertices = adjList.size() ; 

    vector<int>dist(numVertices , INT_MAX) ; 
    dist[src] = 0 ; 

    set<pair<int,int>>s ;

    s.insert({0 , src}) ; 

    while(!s.empty()){
        int currDist = s.begin()->first ; 
        int u = s.begin()->second ; 

        s.erase(s.begin()) ; 

        for(auto it : adjList[u]){
            int v = it.first ; 
            int weight = it.second ; 

            int newDist = currDist + weight ; 

            if(newDist < dist[v]){
                if(dist[v] != 1e9){
                    s.erase({dist[v] , v}) ; 
                }

                dist[v] = newDist ; 
                s.insert({dist[v] , v}) ; 
            }

        }
    }

    return dist ; 
}




int main() {
    int numVertices, numEdges;
    cin >> numVertices >> numEdges;

    // Initialize adjacency list
    vector<vector<pair<int, int>>> adjList(numVertices);

    // Read edges
    for (int i = 0; i < numEdges; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight}); // For undirected graphs
    }

    int source;
    cin >> source;



    // Run Dijkstra's algorithm
    vector<int>distances = dijkstra(source, adjList);

    // Output the shortest distances from the source
    for (int i = 0; i < numVertices; ++i) {
        if (distances[i] == INT_MAX) {
            cout << "INF ";
        } else {
            cout << i << " -> " <<  distances[i] << endl;
        }
    }
    cout << endl;

    return 0;
}
