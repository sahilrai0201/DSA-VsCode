//Given an integer array nums, return the third distinct maximum number in this array. 
//If the third maximum does not exist, return the maximum number.

#include<bits/stdc++.h>
using namespace std;

int thirdMax(vector<int> &nums){
    long long first = LLONG_MIN;
    long long second = LLONG_MIN;
    long long third = LLONG_MIN;

    for(int x : nums){
        //skips duplicates
        if(x == first || x == second || x == third) continue;
        
        if(x > first){
            third = second;
            second = first;
            first = x;
        }
        else if(x > second){
            third = second;
            second = x;
        }
        else if(x > third){
            third = x;
        }
    }
    return (third == LLONG_MIN) ? first : third;
}

int main(){
    int n;
    cout << "Enter the size of an array : " << endl;
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of an array : ";
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    cout << endl;

    int result = thirdMax(nums);

    cout << "Result : " << result << endl;

    return 0;
}