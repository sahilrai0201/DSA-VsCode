// Next Greater Element

#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreater(vector<int> &nums1, vector<int> &nums2){
    stack<int> st;
    unordered_map<int, int> mp;

    for(int i = nums2.size() - 1; i >= 0; i--){
        while(!st.empty() && st.top() <= nums2[i]){
            st.pop();
        }

        if(st.empty()){
            mp[nums2[i]] = -1;
        }
        else{
            mp[nums2[i]] = st.top();
        }

        st.push(nums2[i]);
    }

    vector<int> ans;
    for(auto x : nums1){
        ans.push_back(mp[x]);
    }

    return ans;
}

int main(){
    int n;
    cout << "Enter the size of first array : " << endl;
    cin >> n;

    vector<int> arr1(n);
    cout << "Enter the elements of first array : " << endl;
    for(int i = 0; i < n; i++){
        cin >> arr1[i];
    }

    int m;
    cout << "Enter the size of second array : " << endl;
    cin >> m;

    vector<int> arr2(m);
    cout << "Enter the elements of second array : " << endl;
    for(int i = 0; i < m; i++){
        cin >> arr2[i];
    }

    vector<int> result = nextGreater(arr1, arr2);
    cout << "Next greater elements of first array in second array are : " << endl;
    for(auto x : result){
        cout << x << " ";
    }
    cout << endl;


    return 0;
}



// Output ->
// Enter the size of first array : 
// 3
// Enter the elements of first array : 
// 4 1 2
// Enter the size of second array : 
// 4 
// Enter the elements of second array : 
// 1 3 4 2
// Next greater elements of first array in second array are : 
// -1 3 -1 