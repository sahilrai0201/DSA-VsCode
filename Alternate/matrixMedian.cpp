// Given a row-wise sorted matrix mat[][] of size n*m,
// where the number of rows and columns is always odd. Return the median of the matrix.

#include<bits/stdc++.h>
using namespace std;

int matrixMedian(vector<vector<int>> &arr){
    int n = arr.size();       //No of rows
    int m = arr[0].size();     //No of cols

    int low = INT_MAX;
    int high = INT_MIN;

    for(int i=0; i<n; i++){
        low = min(low, arr[i][0]);
        high = max(high, arr[i][m-1]);
    }

    int desired = (n * m) / 2;

    while(low <= high){
        int mid = low + (high - low) / 2;
        
        int count = 0;

        for(int i=0; i<n; i++){
            count += upper_bound(arr[i].begin(), arr[i].end(), mid) - arr[i].begin();
        }

        if(count <= desired){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    return low;
}

int main(){
    int n;
    cout << "Enter the number of rows : " << endl;
    cin >> n;

    int m;
    cout << "Enter the number of columns : " << endl;
    cin >> m;

    vector<vector<int>> arr(n, vector<int>(m));
    cout << "Enter the elements : " << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }

    int result = matrixMedian(arr);
    cout << "Median of the given matrix is : " << result << endl;

    return 0;
}




// Output : 
// Enter the number of rows : 
// 3 
// Enter the number of columns : 
// 3
// Enter the elements : 
// 1 3 5 2 6 9 3 6 9
// Median of the given matrix is : 5