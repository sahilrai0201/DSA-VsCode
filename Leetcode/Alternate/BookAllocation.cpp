#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> arr, int k, int barrier){
    int n = arr.size();

    int studentCount = 1;
    int pageSum = 0;

    for(int i=0; i<n; i++){
        if(pageSum + arr[i] <= barrier){
            pageSum += arr[i];
        }
        else{
            studentCount++;

            if(studentCount > k || arr[i] > barrier){
                return false;
            }

            pageSum = arr[i];
        }
    }
    return true;
}

int allocateBooks(vector<int> arr, int k){
    int n = arr.size();

    if(k > n) return -1;

    int ans = -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while(low <= high){
        int mid  = low + (high - low) / 2;

        if(isPossible(arr, k, mid)){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int main(){
    int n;
    cout << "Enter the size of an array : " << endl;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the array elements : " << endl;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int k;
    cout << "Enter the tottal number of students : " << endl;
    cin >> k;

    int result = allocateBooks(arr, k);
    cout << "Required answer is : " << result << endl;

    return 0;
}



// Ouput --------------->

// Enter the size of an array : 
// 4
// Enter the array elements : 
// 12 34 67 90
// Enter the tottal number of students : 
// 2
// Required answer is : 113