// Koko Eating Bananas

#include<bits/stdc++.h>
using namespace std;

bool canEat(vector<int> &piles, int h, int k){
    long long hours = 0;

    for(int pile : piles){
        hours += (pile + k - 1) / k;

        if(hours > h){
            return false;
        }
    }
    return true;
}

int minEatingSpeed(vector<int> &piles, int h){
    int low = 1;
    int high = *max_element(piles.begin(), piles.end());

    int ans = high;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(canEat(piles, h, mid)){
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
    cout << "Enter the number of piles : " << endl;
    cin >> n;

    vector<int> piles(n);
    cout << "Enter each pile in the piles : " << endl;
    for(int i=0; i<n; i++){
        cin >> piles[i];
    }

    int h;
    cout << "Enter maximum hour : " << endl;
    cin >> h;

    int result = minEatingSpeed(piles, h);
    cout << "Minimum eating speed is : " << result << endl;

    return 0;
}


// Output ---------->

//Enter the number of piles : 
// 5
// Enter each pile in the piles : 
// 30 11 23 4 20
// Enter maximum hour : 
// 5

// Minimum eating speed is : 30