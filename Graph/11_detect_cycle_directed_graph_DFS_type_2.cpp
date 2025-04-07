
// . Cycle Detection Using Depth-First Search (DFS):

// In DFS, we traverse the graph deeply along each branch before backtracking. To detect cycles in a directed graph using DFS, we can use a visited array with three possible states for each node:​

// 0 (Unvisited): The node has not been visited yet.​

// 1 (Visiting): The node is in the current recursion stack.​

// 2 (Visited): The node and all its descendants have been fully explored.​

// A cycle is detected if we encounter a node that is in the "Visiting" state during the DFS traversal.


#include<bits/stdc++.h>

using namespace std ; 

bool dfs(int node , vector<vector<int>>&adj , vector<int>& visited){
    visited[node] = 1; 

    for(int neighbor : adj[node]){
        if(visited[neighbor] == 0){
            if(dfs(neighbor , adj , visited)){
                return true ; 
            }
        }
        else if(visited[neighbor] == 1){
            return true ; 
        }
    }


    visited[node] = 2 ; 
    return false ;
}


bool hasCycleDFS(vector<vector<int>>& adj, int n) {
    vector<int> visited(n, 0); // Initialize all nodes as "Unvisited"

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) { // If the node is "Unvisited"
            if (dfs(i, adj, visited))
                return true;
        }
    }
    return false;
}





int main() {

	// V = 11, E = 11;
	vector<vector<int>>adj  = {{}, {2}, {3}, {4, 7}, {5}, {6}, {}, {5}, {9}, {10}, {8}};

	int V = adj.size() ; 


	bool ans = hasCycleDFS(adj , V);

	if (ans)
		cout << "True\n";
	else
		cout << "False\n";


    

	return 0;
}
