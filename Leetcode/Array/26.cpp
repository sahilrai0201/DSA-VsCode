//Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place 
//such that each unique element appears only once. The relative order of the elements should be 
//kept the same.
//Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​. After removing duplicates, 
//return the number of unique elements k.
//The first k elements of nums should contain the unique numbers in sorted order. 
//The remaining elements beyond index k - 1 can be ignored.

#include<bits/stdc++.h>
using namespace std;

vector<int> removeDup(vector<int> &arr){
    if(arr.empty()) return {};
    int i = 0;
    int n = arr.size();

    for(int j=1; j<n; j++){
        if(arr[j] != arr[i]){
            i++;
            arr[i] = arr[j];
        }
    }
    arr.resize(i+1);
    return arr;
}

int main(){
    int n;
    cout << "Enter size : " << endl;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements : " << " ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << endl;

    vector<int> result = removeDup(arr);
    for(int i : result){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}