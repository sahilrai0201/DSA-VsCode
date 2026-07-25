// Sum of Subarray Minimums

#include<bits/stdc++.h>
using namespace std;

int sumSubarrayMins(vector<int> &arr){
    int n = arr.size();
    const int MOD = 1e9 + 7;

    vector<int> left(n), right(n);
    stack<int> st;

    // Previous Smaller Element
    for(int i = 0; i < n; i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            st.pop();
        }

        if(st.empty()){
            left[i] = i + 1;
        }
        else{
            left[i] = i - st.top();
        }

        st.push(i);
    }

    while(!st.empty()) st.pop();

    // Next Smaller Element
    for(int i = n - 1; i >= 0; i--){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }

        if(st.empty()){
            right[i] = n - i;
        }
        else{
            right[i] = st.top() - i;
        }

        st.push(i);
    }

    long long ans = 0;

    for(int i = 0; i < n; i++){
        ans = (ans + 1LL * arr[i] * left[i] * right[i]) % MOD;
    }

    return ans;
}

int main(){
    int n;
    cout << "Enter the size of vector : " << endl;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements : " << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int result = sumSubarrayMins(arr);
    cout << "Sum of minimums of all the subarrays formed are : " << result << endl;

    return 0;
}



// Output ->
// Enter the size of vector : 
// 5
// Enter the elements : 
// 11 81 94 43 3
// Sum of minimums of all the subarrays formed are : 444