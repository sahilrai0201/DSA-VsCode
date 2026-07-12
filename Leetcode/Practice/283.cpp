// Move zeros

#include<bits/stdc++.h>
using namespace std;

void moveZeros(vector<int> &arr){
    int n = arr.size();
    int i = 0;

    for(int j=1; j<n; j++){
        if(arr[j] != 0){
            swap(arr[i], arr[j]);
            i++;
        }
    }
}

int main(){
    int n;
    cout << "Enter the size of an array : " << endl;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements : " << endl;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    moveZeros(arr);

    cout << "Max profit is : " << endl; 
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}