#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& nums, int k, int split){
    int n = nums.size();

    int subarray = 1;
    int sum = 0;

    for(int i=0; i<n; i++){
        if(sum + nums[i] <= split){
            sum += nums[i];
        }
        else{
            subarray++;
            sum = nums[i];

            if(subarray > k) return false;
        }
    }
    return true;
}

int splitArray(vector<int>& nums, int k){
    
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);

    int ans = -1;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(isPossible(nums, k, mid)){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int main(){
    int n;
    cout << "Enter the size of an array : " << endl;
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the array elements : " << endl;
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    int k;
    cout << "Enter the number of painters : " << endl;
    cin >> k;

    int result = splitArray(nums, k);
    cout << "Output is : " << result << endl;

    return 0;
}



// Output ------------------------>

// Enter the size of an array : 
// 5
// Enter the array elements : 
// 7 2 5 10 8 
// Enter the number of painters : 
// 2
// Output is : 18