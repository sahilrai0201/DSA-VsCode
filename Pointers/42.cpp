// Trapping Rain Water

#include<bits/stdc++.h>
using namespace std;

int trap(vector<int> &heights){
    int n = heights.size();

    int l = 0;
    int r = n - 1;

    int leftMax = 0;
    int rightMax = 0;
    
    int water = 0;

    while(l < r){
        if(heights[l] < heights[r]){
            if(heights[l] >= leftMax){
                leftMax = heights[l];
            }
            else{
                water += leftMax - heights[l];
            }
            l++;
        }
        else{
            if(heights[r] >= rightMax){
                rightMax = heights[r];
            }
            else{
                water += rightMax - heights[r];
            }
            r--;
        }
    }

    return water;
}

int main(){
    int n;
    cout << "Enter the size of heights array : " << endl;
    cin >> n;
    
    vector<int> heights(n);
    cout << "Enter the elements : " << endl;
    for(int i = 0; i < n; i++){
        cin >> heights[i];
    }

    int result = trap(heights);
    cout << "Max amount of water that heights can hold is : " << result << " units" << endl;

    return 0;
}



// Output ->
// Enter the size of heights array : 
// 6
// Enter the elements : 
// 4 2 0 3 2 5
// Max amount of water that heights can hold is : 9 units