//Given an array nums of integers, return how many of them contain an even number of digits.

#include<bits/stdc++.h>
using namespace std;

int evenNumberDigits(vector<int> nums){
    int result = 0;
    for(int num : nums){
        int count = 0;

        while(num > 0){
            num /= 10;
            count++;
        }
        if(count % 2 == 0){
            result++;
        }
    }
    return result;
}

int main(){
    int n;
    cout << "Enter the size of an array : " << endl;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of an array : " << endl;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << endl;

    int result = evenNumberDigits(arr);
    cout << "Final array with even number of digits is : " << result << endl;
    return 0;
}