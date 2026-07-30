// Return the kth missing element ------------->

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter the size of array : " << endl;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter vector elements : " << endl;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int k;
    cout << "Enter the k : " << endl;
    cin >> k;

    int count = 0;

    for(int num = 1; num <= arr[n-1]; num++){
        bool found = false;

        for(int j=0; j<n; j++){
            if(arr[j] == num){
                found = true;
                break;
            }
        }

        if(!found){
            count++;

            if(count == k){
                cout << "kth  missing element is : " << num;
                return 0;
            }
        }
    }

    cout << "No enough amount of missing numbers are present!" << endl;

    return 0;
}