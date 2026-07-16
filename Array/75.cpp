// Sort Colors

#include<bits/stdc++.h>
using namespace std;

void sortColors(vector<int> &nums){
    int n = nums.size();

    map<int, int> mp;

    for(int i=0; i<n; i++){
        mp[nums[i]]++;
    }

    int index = 0;

    for(auto it : mp){
        int value = it.first;
        int freq = it.second;

        for(int i=0; i<freq; i++){
            nums[index++] = value;
        }
    }
}

int main(){
    int n;
    cout << "Enter the size of an array : " << endl;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of array : " << endl;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    sortColors(arr);
    cout << "Sorted array based on 0s, 1s adn 2s is : " << endl;

    for(auto x : arr){
        cout << x << " ";
    }

    return 0;
}