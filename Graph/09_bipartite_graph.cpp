// ​A bipartite graph is a type of graph in graph theory where the set of vertices can be divided into two distinct, disjoint subsets such that no two vertices within the same subset are adjacent. This means every edge in the graph connects a vertex from one subset to a vertex in the other subset.

// Formal Definition:

// A graph 𝐺 = ( 𝑉 , 𝐸 )  is called bipartite if its vertex set 𝑉 can be partitioned into two disjoint subsets 𝑈 and 𝑉 (i.e., 𝑉 = 𝑈 ∪ 𝑉 and 𝑈 ∩ 𝑉 = ∅  such that every edge in 𝐸  connects a vertex in 𝑈  to a vertex in 𝑉 . ​

// Key Characteristics:

// Two Disjoint Sets: The vertices can be divided into two non-overlapping groups.​

// No Intra-Set Edges: Vertices within the same group do not share edges; all edges are between vertices of different groups.




// Real-Life Example:

// Consider a scenario where we have a set of students and a set of courses. An edge exists between a student and a course if the student is enrolled in that course. This forms a bipartite graph where one subset represents students and the other represents courses, with edges indicating enrollments.


// Applications:

// Matching Problems: Assigning tasks to agents, such as employees to projects, ensuring optimal distribution. ​

// Recommendation Systems: Connecting users to items (e.g., movies, products) based on preferences or past interactions. 

// Network Flow Problems: Modeling relationships in networks, such as data flow between servers and clients. 



// NOTE :: 
// a graph containing an odd-length cycle cannot be bipartite, and conversely, a graph without any odd-length cycles is bipartite.


// so for checking graph is bipartite or not. we can check their is odd length cycle in graph are or not. 


#include <iostream>
#include<bits/stdc++.h>
#include <vector>

using namespace std;

bool dfs(int node, vector<vector<int>>& adj, vector<int>& color) {
    for (int neighbor : adj[node]) {
        if (color[neighbor] == -1) { // If the neighbor hasn't been colored
            color[neighbor] = 1 - color[node]; // Assign the opposite color
            if (!dfs(neighbor, adj, color))
                return false;
        } else if (color[neighbor] == color[node]) {
            return false; // Same color as the current node, not bipartite
        }
    }
    return true;
}

bool isBipartiteDFS(vector<vector<int>>& adj, int n) {
    vector<int> color(n, -1); // -1 indicates that the node hasn't been colored
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) { // If the node hasn't been visited
            color[i] = 0; // Start coloring with color 0
            if (!dfs(i, adj, color))
                return false;
        }
    }
    return true;
}




bool isBipartiteBFS(vector<vector<int>>& adj, int n) {
    vector<int> color(n, -1); // -1 indicates that the node hasn't been colored
    queue<int> q;

    for (int i = 0; i < n; i++) {
        if (color[i] == -1) { // If the node hasn't been visited
            color[i] = 0; // Start coloring with color 0
            q.push(i);

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neighbor : adj[node]) {
                    if (color[neighbor] == -1) { // If the neighbor hasn't been colored
                        color[neighbor] = 1 - color[node]; // Assign the opposite color
                        q.push(neighbor);
                    } else if (color[neighbor] == color[node]) {
                        return false; // Same color as the current node, not bipartite
                    }
                }
            }
        }
    }
    return true;
}






int main() {
    int n = 4; // Number of vertices
    vector<vector<int>> adj(n);

    // Example edges for a bipartite graph
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);

    if (isBipartiteDFS(adj, n)) {
        cout << "The graph is bipartite (checked using DFS)." << endl;
    } else {
        cout << "The graph is not bipartite (checked using DFS)." << endl;
    }

    if (isBipartiteBFS(adj, n)) {
        cout << "The graph is bipartite (checked using BFS)." << endl;
    } else {
        cout << "The graph is not bipartite (checked using BFS)." << endl;
    }

    return 0;
}


