// Minimum Number of Days to Make m Bouquets

#include<bits/stdc++.h>
using namespace std;

bool canMake(vector<int> &bloomDay, int m, int k, int days){
    int bouquets = 0;
    int count = 0;

    for(int bloom : bloomDay){
        if(bloom <= days){
            count++;
        }
        else{
            count = 0;
        }
        if(count == k){
            bouquets++;
            count = 0;
        }
    }
    return bouquets >= m;
}

int minDays(vector<int> &bloomDay, int m, int k){
    int n = bloomDay.size();

    long long flowersNeeded = 1LL * m * k;

    if(flowersNeeded > n) return -1;

    int low = *min_element(bloomDay.begin(), bloomDay.end());
    int high = *max_element(bloomDay.begin(), bloomDay.end());

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(canMake(bloomDay, m, k, mid)){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}

int main(){
    int n;
    cout << "Enter the size of array : " << endl;
    cin >> n;

    vector<int> bloomDay(n);
    cout << "Enter the elements : " << endl;
    for(int i=0; i<n; i++){
        cin >> bloomDay[i];
    }

    int m;
    cout << "Enter the number of bouquets required : " << endl;
    cin >> m;

    int k;
    cout << "Enter the alternate days : " << endl;
    cin >> k;

    int result = minDays(bloomDay, m, k);
    cout << "Minimum number of days required to make bouquets is : " << result << endl;

    return 0;
}