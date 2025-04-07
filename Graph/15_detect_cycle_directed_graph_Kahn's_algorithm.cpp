
// Cycle Detection Using Breadth-First Search (BFS):

// Cycle detection in a directed graph using BFS can be achieved through Kahn's Algorithm for Topological Sorting. The approach involves:​

// Calculating In-Degrees: Compute the in-degree (number of incoming edges) for each node.​

// Enqueuing Zero In-Degree Nodes: Add all nodes with zero in-degree to a queue.​

// Processing the Queue: Iteratively remove nodes from the queue, decrementing the in-degree of their neighbors. If any neighbor's in-degree becomes zero, add it to the queue.​

// Cycle Detection: If, after processing, there are still nodes with non-zero in-degree, it indicates the presence of a cycle.



#include<bits/stdc++.h>

using namespace std ; 

bool hasCycleBFS(vector<vector<int>>& adj , int n){

    vector<int>indegree(n , 0) ; 

    for(int i = 0 ; i< n ; i++){
        for(int neighbor : adj[i]){
            indegree[neighbor]++ ; 
        }
    }


    queue<int>q ; 

    for(int i = 0 ; i<n ; i++){
        if(indegree[i] == 0){
            q.push(i) ; 
        }
    }

    int count = 0 ; 


    while(!q.empty()){
        int node = q.front() ; 
        q.pop() ; 
        count++ ; 

        for(int neighbor : adj[node]){
            indegree[neighbor]--; 

            if(indegree[neighbor] == 0){
                q.push(neighbor) ; 
            }
        }
    }

    // If count doesn't match the number of nodes, there's a cycle
    return count != n ; 
}



int main() {
    int n = 4; // Number of nodes
    std::vector<std::vector<int>> adj(n);

    // Example edges for a directed graph
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0); // This edge creates a cycle
    adj[2].push_back(3);


    if (hasCycleBFS(adj, n)) {
        std::cout << "Cycle detected using BFS." << std::endl;
    } else {
        std::cout << "No cycle detected using BFS." << std::endl;
    }

    return 0;
}



// Explanation:

// DFS Approach: By marking nodes as "Visiting" during traversal, encountering such a node again indicates a back edge, signifying a cycle.​

// BFS Approach (Kahn's Algorithm): By attempting to perform a topological sort, if we cannot include all nodes (i.e., some nodes remain with non-zero in-degree), it indicates the presence of a cycle.