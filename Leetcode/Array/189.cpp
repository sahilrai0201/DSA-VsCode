//Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

#include<bits/stdc++.h>
using namespace std;

void reverseParts(vector<int> &arr, int start, int end){
    while(start < end){
        swap(arr[start++], arr[end--]);
    }
}

void rotate(vector<int> &arr, int k){
    int n = arr.size();
    if(n == 0 || n == 1) return;

    k = k % n;
    if(k == 0) return;

    //to rotate right ->
    reverseParts(arr, 0, n-1);
    reverseParts(arr, 0, k-1);
    reverseParts(arr, k, n-1);

    //to rotate left ->
    // reverseParts(arr, 0, k-1);
    // reverseParts(arr, k, n-1);
    // reverseParts(arr, 0, n-1);
}

int main(){
    int n;
    cout << "Enter size : " << endl;
    cin >> n;

    int k;
    cout << "Enter steps : " << endl;
    cin >> k;

    vector<int> arr(n);
    cout << "Enter elements : " << " ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << endl;

    rotate(arr, k);
    cout << "Rotated array is : " << endl;
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    

    return 0;
}