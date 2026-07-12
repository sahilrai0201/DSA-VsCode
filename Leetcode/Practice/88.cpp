// Mege 2 sorted arrays

#include<bits/stdc++.h>
using namespace std;

void mergeArrays(vector<int> &arr1, int m, vector<int> &arr2, int n){
    int i = m-1;
    int j = n-1;
    int k = m+n-1;

    while(i >= 0 && j >= 0){
        if(arr1[i] > arr2[j]){
            arr1[k] = arr1[i];
            k--;
            i--;
        }
        else{
            arr1[k] = arr2[j];
            k--;
            j--;
        }
    }

    while(j >= 0){
        arr1[k] = arr2[j];
        k--;
        j--;
    }
}

int main(){
    int m;
    cout << "Enter the size of first array : " << endl;
    cin >> m;

    vector<int> arr1(m);
    cout << "Enter the elements : " << endl;
    for(int i=0; i<m; i++){
        cin >> arr1[i];
    }

    int n;
    cout << "Enter the size of second array : " << endl;
    cin >> n;

    vector<int> arr2(n);
    cout << "Enter the elements : " << endl;
    for(int i=0; i<n; i++){
        cin >> arr2[i];
    }

    arr1.resize(m+n);

    mergeArrays(arr1, m, arr2, n);

    cout << "Merged sorted array is : " << endl; 
    for(int i=0; i<m+n; i++){
        cout << arr1[i] << " ";
    }

    return 0;
}