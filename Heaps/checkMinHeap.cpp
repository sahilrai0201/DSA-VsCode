#include<bits/stdc++.h>
using namespace std;

bool isMinHeap(vector<int> &arr, int n){

    for(int i = 0; i < (n/2); i++){
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // Parent > left child
        if(arr[i] > arr[left]){
            return false;
        }

        // Parent > right child
        if(right < n && arr[i] > arr[right]){
            return false;
        }
    }

    return true;
}

int main(){
    int n;
    cout << "Enter the size of arr : " << endl;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of array : " << endl;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    bool answer = isMinHeap(arr, n);
    cout << "Is given array a min heap? : " << answer << endl;

    return 0;
}