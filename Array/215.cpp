//Given an integer array nums and an integer k, return the kth largest element in the array.
//Note that it is the kth largest element in the sorted order, not the kth distinct element.
//Can you solve it without sorting?

#include<bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int> &nums, int k){
    //priority queue
    //min heap
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int num : nums){
        pq.push(num);

        if((int)pq.size() > k){
            pq.pop();
        }
    }
    return pq.top();
}

int main(){
    int n;
    cout << "Enter the size : " << endl;
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements : " << endl;
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    int k;
    cout << "Enter the k which will give you kth largest element in the array : " << endl;
    cin >> k;

    int result = findKthLargest(nums, k);
    cout << "The kth largest element in the given array is : " << result << endl;

    return 0;
}