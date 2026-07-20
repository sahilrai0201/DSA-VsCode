#include<bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, int n, vector<vector<int>> visited, vector<vector<int>> &maze){
    if((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && maze[x][y] == 1){
        return true;
    }
    else{
        return false;
    }
}

void solve(vector<vector<int>> &maze, int n, vector<string> &ans, int x, int y, 
    vector<vector<int>> visited, string path){
    //you have visited x, y here
    //base case
    if(x == n-1 && y == n-1){
        ans.push_back(path);
        return;
    }
    visited[x][y] = 1;
        
    //4 choices -> D, L, R, U
        
    //down
    int newx = x+1;
    int newy = y;
    if(isSafe(newx, newy, n, visited, maze)){
        path.push_back('D');
        solve(maze, n, ans, newx, newy, visited, path);
        path.pop_back();
    }
        
    //left
    newx = x;
    newy = y-1;
    if(isSafe(newx, newy, n, visited, maze)){
        path.push_back('L');
        solve(maze, n, ans, newx, newy, visited, path);
        path.pop_back();
    }
        
    //right
    newx = x;
    newy = y+1;
    if(isSafe(newx, newy, n, visited, maze)){
        path.push_back('R');
        solve(maze, n, ans, newx, newy, visited, path);
        path.pop_back();
    }
        
    //up
    newx = x-1;
    newy = y;
    if(isSafe(newx, newy, n, visited, maze)){
        path.push_back('U');
        solve(maze, n, ans, newx, newy, visited, path);
        path.pop_back();
    }
        
    //backtrack
    visited[x][y] = 0;
}
    
vector<string> ratInMaze(vector<vector<int>>& maze) {
    // code here
    int n = maze.size();
    vector<string> ans;
        
    if(maze[0][0] == 0) return ans;
        
    int srcx = 0, srcy = 0;
        
    vector<vector<int>> visited = maze;
    //initialized with 0
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visited[i][j] = 0;
        }
    }
        
    string path = "";
        
    solve(maze, n, ans, srcx, srcy, visited, path);
    
    sort(ans.begin(), ans.end());   // for lexicographically sorted answer
        
    return ans;
};

int main(){
    int n;
    cout << "Enter the size of maze : " << endl;
    cin >> n;

    vector<vector<int>> maze(n, vector<int>(n));
    cout << "Enter the maze elements : " << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> maze[i][j];
        }
    }

    vector<string> ans = ratInMaze(maze);

    for(int i=0; i<(int)ans.size(); i++){
        cout << "[ " <<  ans[i] << " ]";
    }

    return 0;
}



// Output ->
// Enter the size of maze : 
// 4
// Enter the maze elements : 
// 1 0 0 0 1 1 0 1 1 1 0 0 0 1 1 1
// [ DDRDRR ][ DRDDRR ]