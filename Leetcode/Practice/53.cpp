// Given an integer array nums, find the subarray with the largest sum, and return its sum.

#include<bits/stdc++.h>
using namespace std;

int maxSubarray(vector<int> &arr){
    int maxSum = arr[0];
    int currSum = arr[0];

    for(int i=1; i<(int)arr.size(); i++){
        currSum = max(arr[i], currSum + arr[i]);
        maxSum = max(maxSum, currSum);
    }

    return maxSum;
}

int main(){
    int n;
    cout << "Enter the size of an array : " << endl;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements : " << endl;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int result = maxSubarray(arr);
    cout << "Max profit is : " << result << endl; 

    return 0;
}