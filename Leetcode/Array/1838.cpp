//The frequency of an element is the number of times it occurs in an array.
//You are given an integer array nums and an integer k. 
//In one operation, you can choose an index of nums and increment the element at that index by 1.
//Return the maximum possible frequency of an element after performing at most k operations.

#include<bits/stdc++.h>
using namespace std;

int countFreq(vector<int> &arr, int n, int k){
    sort(arr.begin(), arr.end());

    int left = 0;
    long long sum = 0;
    int maxFreq = 0;

    for(int right = 0; right < n; right++){
        sum = sum + arr[right];

        //check if operations needed exceeds k
        while(arr[right] * (right - left + 1) - sum > k){
            sum = sum - arr[left];
            left++;
        }
        maxFreq = max(maxFreq, right - left + 1);
    }
    return maxFreq;
}

int main(){
    int n;
    cout << "size of array : " << endl;
    cin >> n;

    int k;
    cout << "Enter k : " << endl;
    cin >> k;

    vector<int> arr(n);
    cout << "Enter the elements of array : " << endl;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int result = countFreq(arr, n, k);
    cout << "Max frequency is : " << result << endl;
    return 0;
}