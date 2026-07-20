// N queens

#include<bits/stdc++.h>
using namespace std;

void addSolution(vector<vector<string>> &ans, vector<vector<int>> &board, int n){
    vector<string> temp;

    for(int i=0; i<n; i++){
        string row = "";
        for(int j=0; j<n; j++){
            if(board[i][j] == 1){
                row.push_back('Q');
            }
            else{
                row.push_back('-');
            }
        }
        temp.push_back(row);
    }
    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>> &board, int n){
    int x = row;
    int y = col;

    while(y >= 0){
        if(board[x][y] == 1){
            return false;
        }
        y--;
    }

    x = row;
    y = col;
    while(x >= 0 && y >= 0){
        if(board[x][y] == 1){
            return false;
        }
        x--;
        y--;
    }

    x = row;
    y = col;
    while(x < n && y >= 0){
        if(board[x][y] == 1){
            return false;
        }
        x++;
        y--;
    }

    return true;
}

void solve(int col, vector<vector<int>> &board, vector<vector<string>> &ans, int n){
    if(col == n){
        addSolution(ans, board, n);
        return;
    }

    for(int row = 0; row < n; row++){
        if(isSafe(row, col, board, n)){
            board[row][col] = 1;
            solve(col + 1, board, ans, n);

            board[row][col] = 0;
        }
    }
}

vector<vector<string>> NQueens(int n){
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<string>> ans;

    solve(0, board, ans, n);
    return ans;
}

int main(){
    int n;
    cout << "Enter number of queens : " << endl;
    cin >> n;

    vector<vector<string>> result = NQueens(n);

    cout << "Possible combinations of N Queens are : " << endl;

    for(auto x : result){
        for(auto y : x){
            cout << y << endl;
        }
    }
    cout << endl;

    return 0;
}