
// topological sorting refers to the linear ordering of vertices in a Directed Acyclic Graph (DAG) such that for every directed edge  𝑢 → 𝑣 , vertex 𝑢  precedes vertex 𝑣  in the ordering. This concept is pivotal in scenarios where certain tasks must be performed before others due to inherent dependencies. ​

// Key Characteristics:

// Applicability to DAGs: Topological sorting is only feasible for Directed Acyclic Graphs. The absence of cycles ensures a valid linear ordering of tasks or events.​
// Wikipedia

// Non-Uniqueness: A DAG can have multiple valid topological orderings. The specific ordering can vary based on the algorithm used and the structure of the graph




// llustrative Example:

// Consider a set of tasks with dependencies:​
// Task A: No prerequisites.
// Task B: Depends on Task A.
// Task C: Depends on Task A.
// Task D: Depends on Tasks B and C.

// Representing this as a DAG:​
// A → B​
// A → C​
// B → D​
// C → D​

// A valid topological ordering would be: A, B, C, D. This ordering ensures that each task is scheduled only after all its prerequisites have been completed.


// Example 2 : 

//     5 -> 0 -> 4 
//     |         |
//     v         v
//     2 -> 3 -> 1


// topological sort for this : 
// 5 , 4 , 2 , 3 , 1 , 0 
// 4 , 5 , 2 , 3 , 1 , 0 
// 5 , 4 , 0 , 2 , 3 , 1 

// => all are true topological sorts. 


// Each of these orderings respects the direction of edges, ensuring that for every directed edge  𝑢 → 𝑣 , 𝑢 precedes 𝑣.​

// Reason for Multiple Orderings:

// The multiple valid orderings stem from vertices that are not directly connected by a path, allowing their positions to be swapped in the ordering. In the example, vertices 0 and 2 can appear in different orders relative to each other as long as their individual dependencies are respected.

#include<bits/stdc++.h>
using namespace std ; 

void dfs(int node , int vis[] , stack<int>& st , vector<int> adj[]){
    vis[node] = 1 ;
    
    for(auto it : adj[node]){
        if(!vis[it]) dfs(it , vis , st , adj) ; 
    }

    st.push(node) ; 
}

vector<int> topologicalSortDFS(int V , vector<int>adj[]){
    int vis[V] = {0} ;

    stack<int>st ; 

    for(int i = 0 ; i< V ; i++){
        if(!vis[i]){
            dfs(i , vis , st , adj) ; 
        }
    }

    vector<int>ans ; 

    while(!st.empty()){
        ans.push_back(st.top()) ; 
        st.pop() ; 
    }

    return ans ; 
}

// This function only work , when there is no cycle. Else , iteration not stop. 


int main() {
    int V = 6; // Number of vertices
    vector<int> adj[V];

    // Example graph:
    // 5 → 0 → 4
    // ↓         ↓
    // 2 → 3 → 1

    adj[5].push_back(0);
    adj[5].push_back(2);
    adj[0].push_back(4);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);



    // Using DFS-based approach
    vector<int> topo_order_dfs = topologicalSortDFS(V, adj);
    cout << "Topological Sort (DFS-based): ";
    for (int v : topo_order_dfs) {
        cout << v << " ";
    }
    cout << endl;


    // Topological Sort (DFS-based): 5 2 3 0 4 1

    return 0;
}

