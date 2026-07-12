//Given an array nums of size n, return the majority element.
//The majority element is the element that appears more than ⌊n / 2⌋ times. 
//You may assume that the majority element always exists in the array.

#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &nums){
    int n = nums.size();
    int candidate = nums[0];
    int vote = 1;

    for(int i=1; i<n; i++){
        if(vote == 0){
            candidate = nums[i];
            vote = 1;
        }
        else if(nums[i] == candidate){
            vote++;
        }
        else{
            vote--;
        }
    }
    return candidate;
}

int main(){
    int n;
    cout << "Enter the size of array : " << endl;
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements : " << endl;
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    int result = majorityElement(nums);

    cout << "Element with majority of occurrence in the given array is : " << result << endl;

    return 0;
}


// Enter the size of array : 
// 7
// Enter the elements : 
// 2 2 1 1 1 2 2
// Element with majority of occurrence in the given array is : 2