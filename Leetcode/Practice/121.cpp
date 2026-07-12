// Best Time to Buy and Sell Stock

#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices){
    int minPrice = INT_MAX;
    int profit = 0;

    for(int i=0; i<(int)prices.size(); i++){
        minPrice = min(minPrice, prices[i]);
        profit = max(profit, prices[i] - minPrice);
    }

    return profit;
}

int main(){
    int n;
    cout << "Enter the size of an array : " << endl;
    cin >> n;

    vector<int> prices(n);
    cout << "Enter the elements : " << endl;
    for(int i=0; i<n; i++){
        cin >> prices[i];
    }

    int result = maxProfit(prices);
    cout << "Max profit is : " << result << endl; 

    return 0;
}