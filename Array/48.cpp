#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> rotateImage(vector<vector<int>> &m){
    int n = m.size();

    //transpose
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            swap(m[i][j], m[j][i]);   
        }
    }

    //reverse each row
    for(int i=0; i<n; i++){
        reverse(m[i].begin(), m[i].end());
    }

    return m;
}

int main(){
    int n;
    cout << "Enter the size of matrix : " << endl;
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));

    cout << "Enter the elements of the matrix : " << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> mat[i][j];
        }
    }

    vector<vector<int>> result = rotateImage(mat);

    for(auto i : result){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}