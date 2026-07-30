// Subarray Sum Equals K

#include<bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &nums, int k){
    unordered_map<int, int> mp;
    mp[0] = 1;

    int sum = 0;
    int count = 0;

    for(int num : nums){
        sum += num;

        count += mp[sum - k];

        mp[sum]++;
    }

    return count;
}    

int main(){
    int n;
    cout << "Enter the size of array : " << endl;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements : " << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int k;
    cout << "Enter k : " << endl;
    cin >> k;

    int answer = subarraySum(arr, k);
    cout << "Number of subarrays in given array with sum equals to k are : " << answer << endl;

    return 0;
}




// Output ->
// Enter the size of array : 
// 3
// Enter the elements : 
// 1 2 3 
// Enter k : 
// 3
// Number of subarrays in given array with sum equals to k are : 2