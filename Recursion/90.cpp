// Subset 2 -> contains duplicate elements : 

#include<bits/stdc++.h>
using namespace std;

void solve(int index, vector<int> &arr, vector<int> output, vector<vector<int>> &ans){
    ans.push_back(output);

    for(int i = index; i < (int)arr.size(); i++){
        if(i > index && arr[i] == arr[i-1]) continue;

        output.push_back(arr[i]);
        solve(i + 1, arr, output, ans);
        output.pop_back();
    }
}

vector<vector<int>> subsets(vector<int> &arr){
    vector<vector<int>> ans;
    vector<int> output;

    sort(arr.begin(), arr.end());

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