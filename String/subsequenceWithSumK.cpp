// Subsequence with Sum K

#include<bits/stdc++.h>
using namespace std;

int solve(int index, vector<int> &arr, int sum, int k, vector<int> &curr){

    if(index == (int)arr.size()){
        if(sum == k){
            for(int x : curr){
                cout << x << " ";
            }
            cout << endl;

            return 1;
        }
        return 0;
    }

    int count = 0;

    curr.push_back(arr[index]);
    count += solve(index + 1, arr, sum + arr[index], k, curr);
    curr.pop_back();

    count += solve(index + 1, arr, sum, k, curr);

    return count;
}

// bool solve(int index, vector<int> &arr, int sum, int k){
//     if(index == (int)arr.size()){
//         return (sum == k);
//     }

//     if(solve(index + 1, arr, sum + arr[index], k)){
//         return true;
//     }

//     if(solve(index + 1, arr, sum, k)){
//         return true;
//     }

//     return false;
// }

int subsequenceSum(vector<int> &arr, int k){
    vector<int> curr;
    return solve(0, arr, 0, k, curr);
}

int main(){
    int n;
    cout << "Size of array : " << endl;
    cin >>n;

    vector<int> arr(n);
    cout << "Enter array elements : " << endl;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    } 

    int k;
    cout << "Enter sum : " << endl;
    cin >> k;

    int total = subsequenceSum(arr, k);

    cout << "total number of subsequneces with sum k : " << total << endl;

    return 0;
}




// ********************************************************
// Output :                                               

// Size of array :                                        
// 7                                                      
// Enter array elements : 
// 10 1 2 7 6 1 5
// Enter sum : 
// 8
// Subsequnece with sum k present or not (T/F) ? : 1