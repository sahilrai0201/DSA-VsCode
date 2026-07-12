// Print subarray and its maximum sum - Extended version

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cout << "Enter the size of an array : " << endl;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements : " << endl;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int maxSum = INT_MIN, currSum = 0;

    int start = 0, end = 0, tempStart = 0;

    for(int i=0; i<n; i++){
        currSum += arr[i];

        if(currSum > maxSum){
            maxSum = currSum;
            start = tempStart;
            end = i;
        }
        if(currSum < 0){
            currSum = 0;
            tempStart = i + 1;
        }
    }

    cout << "Max Sum is : " << maxSum << endl;
    cout << "Subarray : ";
    for(int i=start; i<=end; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}


// Output : 
// Enter the size of an array : 
// 9
// Enter the elements : 
// -2 1 -3 4 -1 2 1 -5 4
// Max Sum is : 6
// Subarray : 4 -1 2 1