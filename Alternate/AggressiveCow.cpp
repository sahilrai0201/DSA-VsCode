// You are given an array with unique elements of stalls[], which denote the positions of stalls. 
// You are also given an integer k which denotes the number of aggressive cows. 
// The task is to assign stalls to k cows such that the minimum distance between any two of 
// them is the maximum possible.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canPlace(vector<int> &stalls, int k, int dist){
    int count = 1;
    int lastPos = stalls[0];

    for(int i=1; i<(int)stalls.size(); i++){
        if(stalls[i] - lastPos >= dist){
            count++;
            lastPos = stalls[i];

            if(count >= k) return true;
        } 
    }
    return false;
}

int aggressiveCow(vector<int> &stalls, int k){
    sort(stalls.begin(), stalls.end());

    int low = 1;
    int high = stalls.back() - stalls.front();

    int ans = 0;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(canPlace(stalls, k, mid)){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}

int main(){
    int n;
    cout << "Enter the size of an array : " << endl;
    cin >> n;

    vector<int> stalls(n);
    cout << "Enter the elements : " << endl;
    for(int i=0; i<n; i++){
        cin >> stalls[i];
    }

    int k;
    cout << "Enter the number of cows : " << endl;
    cin >> k;

    int result = aggressiveCow(stalls, k);
    cout << "Minium distance between each cow will be : " << result << endl;

    return 0;
}


