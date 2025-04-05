
#include<bits/stdc++.h>
using namespace std; 

// using bfs ; 

// Time Complexity O(N + M)	
// Space ComplexityO(N) (Queue + Visited Array)

bool detect(int src , vector<vector<int>>& adj , vector<bool>& vis){
    vis[src] = 1; 

    // storing (node , parend node) ; 
    queue<pair<int,int>>q ; 
    q.push({src , -1}) ; 

    while(!q.empty()){
        int node = q.front().first ; 
        int parent = q.front().second ; 
        q.pop() ; 

        for(auto adjNode : adj[node]){
            if(!vis[adjNode]){
                vis[adjNode] =1 ; 
                q.push({adjNode , node}) ; 
            }

            else if(parent != adjNode){
                return true ; 
            }
        }
    }

    return false ;
}

bool detectCycleBFS(vector<vector<int>>& adj){
    int n = adj.size() ; 
    vector<bool>visited(n , false) ; 

    for(int startnode = 0 ; startnode < n ; startnode++){
        if(!visited[startnode]){
            if(detect(startnode , adj , visited)) return true ; 
        }
    }

    return false ; 


}


int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> adj(n);
    cout << "Enter " << m << " edges (0-based indexing):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }

    if (detectCycleBFS(adj)) {
        cout << "Cycle Detected\n";
    } else {
        cout << "No Cycle\n";
    }

    return 0;
}

