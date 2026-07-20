// WORD SEARCH

#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<char>> &board, string &word, int row, int col, int index){
    if(index == (int) word.length()){
        return true;
    }

    int m = board.size();
    int n = board[0].size();

    if(row < 0 || row >= m || col < 0 || col >= n){
        return false;
    }

    if(board[row][col] != word[index]){
        return false;
    }

    char ch = board[row][col];

    board[row][col] = '#';

    bool found = 
        dfs(board, word, row - 1, col, index + 1) || 
        dfs(board, word, row + 1, col, index + 1) ||
        dfs(board, word, row, col - 1, index + 1) ||
        dfs(board, word, row, col + 1, index + 1);

    board[row][col] = ch;    

    return found;    
}

bool wordExist(vector<vector<char>> &board, string &word){
    int m = board.size();
    int n = board[0].size();

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(board[i][j] == word[0]){
                if(dfs(board, word, i, j, 0)){
                    return true;
                }
            }
        }
    }

    return false;
}

int main(){
    int m;
    cout << "Enter row size : " << endl;
    cin >> m;

    int n;
    cout << "Enter column size : " << endl;
    cin >> n;

    vector<vector<char>> board(m, vector<char>(n));
    cout << "Enter the characters in the grid : " << endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }

    string word;
    cout << "Enter the string word : " << endl;
    cin  >> word;

    bool result = wordExist(board, word);
    cout << "Can we form word from the characters of grid (T/F) ? : " << result << endl;

    return 0;
}



// Output ->
// Enter row size : 
// 3
// Enter column size : 
// 4
// Enter the characters in the grid : 
// A B C E S F C S A D E E
// Enter the string word : 
// ABCCED
// Can we form word from the characters of grid (T/F) ? : 1