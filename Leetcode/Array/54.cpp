//Given an m x n matrix, return all elements of the matrix in spiral order.

#include<bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix){
    vector<int> result;
    if(matrix.empty()) return result;

    int top = 0;  //first row
    int bottom = matrix.size() - 1;  //last row
    int left = 0;    //first column
    int right = matrix[0].size() - 1;  //last column

    while(top <= bottom && left <= right){
        //traverse left to right
        for(int i=left; i<=right; ++i){
            result.push_back(matrix[top][i]);
        }
        ++top;

        //traverse top to bottom
        for(int i=top; i<=bottom; ++i){
            result.push_back(matrix[i][right]);
        }
        --right;

        //traverse right to left
        if(top <= bottom){
            for(int i=right; i>=left; --i){
                result.push_back(matrix[bottom][i]);
            }
            --bottom;
        }

        //traverse bottom to top
        if(left <= right){
            for(int i=bottom; i>=top; --i){
                result.push_back(matrix[i][left]);
            }
            ++left;
        }
    }
    return result;
}

int main(){
    int n;
    cout << "Enter rows : " << endl;
    cin >> n;

    int m;
    cout << "Enter column : " << endl;
    cin >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    cout << "Enter the elements : " << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> matrix[i][j];
        }
    }

    vector<int> result = spiralOrder(matrix);
    cout << "Spiral order for the given matrix is : " << endl;
    for(auto i : result){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}