
// Problem Explanation
// You're given a sorted dictionary of words in an alien language. Your job is to determine the correct order of characters (alphabetical order) in that alien language based on how the words are sorted.

// The characters are all lowercase English letters, but their order may differ from the standard English order.


// Input
// N: Number of words in the dictionary.
// K: Number of unique characters.
// dictionary[]: An array of N strings sorted in alien language order.

// Example :-

// N = 3
// K = 3
// dictionary = ["caa", "aaa", "aab"]

// Here, from the words:

// "caa" vs "aaa" → first mismatch is 'c' vs 'a' ⇒ c comes before a
// "aaa" vs "aab" → first mismatch is 'a' vs 'b' ⇒ a comes before b
// So the alien order is: c → a → b


#include<bits/stdc++.h>
using namespace std ; 

string findOrder(vector<string>& dict , int N , int K){
    vector<int>adj[K] ;

    // Build graph by comparing adjacent words ; 

    for(int i = 0 ; i< N-1 ; i++){
        string word1 = dict[i] ;
        string word2 = dict[i+1] ;

        int len = min(word1.length() , word2.length()) ; 

        for(int j = 0 ; j < len ; j++){
            if(word1[j] != word2[j]){
                adj[word1[j]-'a'].push_back(word2[j]-'a') ; 
                break ; // only the first differing character helps ; 
            }
        }
    }

    vector<int>indegree(K , 0) ; 

    for(int u = 0 ; u < K ; u++){
        for(int v : adj[u]){
            indegree[v]++ ; 
        }
    }


    queue<int>q ; 

    for(int i = 0 ;i < K ; i++){
        if(indegree[i] == 0){
            q.push(i) ; 
        }
    }

    string order ;

    while(!q.empty()){
        int u = q.front() ; 
        q.pop() ; 
        order+= (char)(u+'a') ; 

        for(int v : adj[u]){
            indegree[v]-- ; 

            if(indegree[v] == 0){
                q.push(v) ; 
            }
        }
    }

    return order ; 
}



// Driver code for testing
int main() {
    int N = 3, K = 3;
    vector<string> dict = {"caa", "aaa", "aab"};
    
    string res = findOrder(dict, N, K);
    
    // Check result size to confirm it's valid (for the judge)
    if (res.length() == K)
        cout << "true\n";
    else
        cout << "false\n";
    
    // Optional: print the alien order
    cout << "Alien character order: " << res << endl;

    return 0;
}


// Notes: 
// The solution uses Graph + Topological Sorting (Kahn's Algorithm).
// It ensures that if K characters are involved, the result contains all of them in a valid order.
