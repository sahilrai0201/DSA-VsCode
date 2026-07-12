//Given an integer array nums, move all 0's to the end of it while maintaining the relative 
//order of the non-zero elements.
//Note that you must do this in-place without making a copy of the array.

#include<bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int> &arr){
    int n = arr.size();
    int i = 0;

    for(int j=0; j<n; j++){
        if(arr[j] != 0){
            swap(arr[i], arr[j]);
            i++;
        }
    }
}

int main(){
    int n;
    cout << "Enter size : " << endl;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements : ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << endl;

    moveZeroes(arr);
    cout << "Final Array after moving zeroes at end : " << endl;
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}