#include<bits/stdc++.h>
using namespace std;

bool isKSortedArray(vector<int> &arr, int k){
    int n = arr.size();

    vector<pair<int, int>> sorted;

    for(int i = 0; i < n; i++){
        sorted.push_back({arr[i], i});
    }

    sort(sorted.begin(), sorted.end());

    for(int i = 0; i < n; i++){
        int originalIndex = sorted[i].second;

        if(abs(originalIndex - i) > k){
            return false;
        }
    }

    return true;
}

int main(){
    int n;
    cout << "Size of array : " << endl;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements : " << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int k;
    cout << "Enter k : " << endl;
    cin >> k;

    bool answer = isKSortedArray(arr, k);

    cout << "Is the atmost between original array elements and sorted array elements greater than k? : " << answer << endl;

    return 0;
}