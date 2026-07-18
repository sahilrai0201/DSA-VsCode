// Subsets 1

#include<bits/stdc++.h>
using namespace std;

void solve(int index, vector<int> &arr, vector<int> output, vector<vector<int>> &ans){
    if(index >= (int)arr.size()){
        ans.push_back(output);
        return;
    }

    // Exclude
    solve(index + 1, arr, output, ans);

    // Include
    int element = arr[index];
    output.push_back(element);
    solve(index + 1, arr, output, ans);
}

vector<vector<int>> subsets(vector<int> &arr){
    vector<vector<int>> ans;
    vector<int> output;
    solve(0, arr, output, ans);
    return ans;
}

int main(){
    int n;
    cout << "Size of array : " << endl;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements : " << endl;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    vector<vector<int>> result = subsets(arr);

    cout << "All subsets of the given array are : " << endl;

    for(auto p : result){
        cout << "[ ";
        for(auto q : p){
            cout << q << " ";
        }
        cout << "]" << endl;
    }
    cout << endl;

    return 0;
}