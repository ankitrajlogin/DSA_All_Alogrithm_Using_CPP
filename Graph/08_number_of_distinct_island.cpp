// Problem Statement: Given a boolean 2D matrix grid of size N x M. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is equal to another (not rotated or reflected).

// Input:
// grid = [
//   [1, 1, 0, 0, 0],
//   [1, 1, 0, 0, 0],
//   [0, 0, 0, 1, 1],
//   [0, 0, 0, 1, 1]
// ]

// Output:
// 1


#include<iostream>
#include<vector>
#include<set>
#include<string>

using namespace std ;


void dfs(int x , int y , vector<vector<int>>& grid , vector<vector<bool>>&visited , string& shape , int baseX , int baseY){
    int n = grid.size() ; 
    int m = grid[0].size() ; 

    vector<pair<int,int>> directions = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}} ; 

    vector<char>dirChars = {'U' , 'D' , 'L' , 'R'} ; 

    visited[x][y] = true ; 

    shape+= 'S'  ; 

    for(int i = 0 ; i< 4 ; i++){
        int newX = x + directions[i].first ; 
        int newY = y + directions[i].second ; 

        if(newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 1 && !visited[newX][newY]){
            shape += dirChars[i] ;
            dfs(newX , newY , grid , visited , shape , baseX , baseY) ; 
        }
    }

    shape += 'E' ; // End fo an island part ; 
}


int countDistinctIslands(vector<vector<int>>& grid){
    int n = grid.size() ; 
    int m = grid[0].size() ; 


    vector<vector<bool>>visited(n , vector<bool>(m , false)) ; 

    set<string>uniqueShapes ; 

    for(int i = 0 ; i< n ; i++){
        for(int j = 0;  j< m ; j++){
            if(grid[i][j] == 1 && !visited[i][j]){
                string shape = "" ; 

                dfs(i , j , grid , visited , shape , i , j) ; 
                uniqueShapes.insert(shape) ; 
            }
        }
    }

    return uniqueShapes.size(); 
}



int main(){
    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1}
    };

    cout << "Number of distinct islands: " << countDistinctIslands(grid) << endl;

    return 0;
}


// Time Complexity:
// DFS Traversal: Each cell is visited once, resulting in a time complexity of O(n * m), where n is the number of rows and m is the number of columns in the grid.​
// LeetCode
// Shape Storage: In the worst case, storing all unique shapes also takes O(n * m) time.​
// Therefore, the overall time complexity is O(n * m).​


// Space Complexity:
// Visited Array: O(n * m) space is used to keep track of visited cells.​
// Recursion Stack: In the worst case (a completely filled grid), the recursion stack may also consume O(n * m) space.​
// Set for Shapes: Storing the shapes of islands requires additional space, but since each cell contributes to only one shape, this also results in O(n * m) space.
// Thus, the overall space complexity is O(n * m).