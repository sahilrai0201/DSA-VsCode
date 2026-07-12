// You are given a 2D binary array arr[][] consisting of only 1s and 0s. 
// Each row of the array is sorted in non-decreasing order. 
// Your task is to find and return the index of the first row that contains the maximum number of 1s.
// If no such row exists, return -1.

//TOP-RIGHT CORNER APPROACH : TC = O(N+M) & SC = O(1) 

#include<bits/stdc++.h>
using namespace std;

int rowWithMax1s(vector<vector<int>> &arr){

    int n = arr.size();          //No of rows
    int m = arr[0].size();        //No of columns

    int i = 0, j = m-1;

    int ans = -1;

    while(i < n && j >= 0){
        if(arr[i][j] == 1){
            ans = i;
            j--;           //move left
        }
        else{
            i++;  //move down
        }
    }

    return ans;
}

int main(){
    int n;
    cout << "Enter the number of rows : " << endl;
    cin >> n;

    int m;
    cout << "Enter the number of columns : " << endl;
    cin >>m;

    vector<vector<int>> arr(n, vector<int>(m));
    cout << "Enter the elements : " << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }

    int result = rowWithMax1s(arr);
    cout << "Row with maximum number of 1s is : " << result << endl;

    return 0;
}



// Output :
// Enter the number of rows : 
// 4
// Enter the number of columns : 
// 4
// Enter the elements : 
// 0 1 1 1 0 0 1 1 1 1 1 1 0 0 0 0
// Row with maximum number of 1s is : 2