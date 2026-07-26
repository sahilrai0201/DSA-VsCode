// Largest Rectangle in Histogram

#include<bits/stdc++.h>
using namespace std;

// Find index of Next Smaller Element
vector<int> nextSmallerElement(vector<int> arr, int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i = n - 1; i >= 0; i--){
        int curr = arr[i];

        // Remove elements >= current
        while(s.top() != -1 && arr[s.top()] >= curr){
            s.pop();
        }

        // Store next smaller index
        ans[i] = s.top();

        // Push current index
        s.push(i);
    }
    return ans;
}

// Find index of Previous Smaller Element
vector<int> prevSmallerElement(vector<int> arr, int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i = 0; i < n; i++){
        int curr = arr[i];

        // Remove elements >= current
        while(s.top() != -1 && arr[s.top()] >= curr){
            s.pop();
        }

        // Store previous smaller index
        ans[i] = s.top();

        // Push current index
        s.push(i);
    }
    return ans;
}

int largestRectArea(vector<int> &heights){
    int n = heights.size();

    vector<int> next(n);
    next = nextSmallerElement(heights, n);
    
    vector<int> prev(n);
    prev = prevSmallerElement(heights, n);

    int area = INT_MIN;

    for(int i=0; i<n; i++){
        int l = heights[i];

        if(next[i] == -1){
            next[i] = n;
        }

        int b = next[i] - prev[i] - 1;

        int newArea = l * b;

        area = max(area, newArea);
    }

    return area;
}

int main(){
    int n;
    cout << "Enter the size of array : " << endl;
    cin >> n;

    vector<int> heights(n);
    cout << "Enter the elements : " << endl;
    for(int i=0; i<n; i++){
        cin >> heights[i];
    }

    int result = largestRectArea(heights);

    cout << "Largest reactangle in a histogram is : " << result << endl;

    return 0;
}



// Output ->
// Enter the size of array : 
// 6
// Enter the elements : 
// 2 1 5 6 2 3
// Largest reactangle in a histogram is : 10