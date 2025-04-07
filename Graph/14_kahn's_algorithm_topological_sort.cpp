
// ​Kahn's Algorithm is a method used to perform a topological sort on a Directed Acyclic Graph (DAG). A topological sort provides a linear ordering of vertices such that for every directed edge 𝑢 → 𝑣 , vertex 𝑢  precedes vertex 𝑣  in the ordering. This is particularly useful in scenarios where certain tasks must be performed before others, such as scheduling jobs, resolving symbol dependencies in linkers, or determining the order of compilation tasks.​

// Use Cases of Kahn's Algorithm:

// Task Scheduling: In project management, tasks often have dependencies. Kahn's Algorithm helps determine an order to execute tasks without violating any dependency constraints.​

// Course Prerequisites: In academic settings, courses may have prerequisites. Using Kahn's Algorithm, one can determine a valid sequence to take courses.​

// Compilation Order: In software development, certain modules may depend on others. Kahn's Algorithm assists in determining the order in which modules should be compiled.​

// Data Serialization: When serializing objects with interdependencies, Kahn's Algorithm can help determine the order to serialize objects to maintain consistency.​


#include<bits/stdc++.h>
using namespace std ; 

vector<int> topologicalSortKahn(int V , vector<int>adj[]){
    int indegree[V] = {0} ;

    for(int i = 0 ;i < V ; i++){
        for(auto it : adj[i]){
            indegree[it]++ ; 
        }
    }

    queue<int>q ; 

    for(int i = 0 ;i < V ; i++){
        if(indegree[i] == 0){
            q.push(i)  ; 
        }
    }

    vector<int>topo ; 

    // o(v+e) ; 

    while(!q.empty()){
        int node = q.front() ; 
        q.pop() ; 

        topo.push_back(node) ; 

        for(auto it : adj[node]){
            indegree[it]-- ; 

            if(indegree[it] == 0) q.push(it) ; 
        }
    }

    if(topo.size() != V){
        cout << "The graph has a cycle; topological sorting is not possible." << endl;
        return {}; 
    }

    return topo ; 
}



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

    vector<int> topo_order = topologicalSortKahn(V, adj);
    cout << "Topological Sort (Kahn's Algorithm): ";
    for (int v : topo_order) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}

