// Given n pairs of parentheses, write a function to generate all combinations 
// of well-formed parentheses.

#include<bits/stdc++.h>
using namespace std;

int solve(int open, int close, int n, string curr, vector<string> &ans){
    if((int)curr.length() == 2 * n){
        ans.push_back(curr);
        return 1;
    }

    int count = 0;

    if(open < n){
        count += solve(open + 1, close, n, curr + '(', ans);
    }

    if(close < open){
        count += solve(open, close + 1, n, curr + ')', ans);
    }

    return count;
}

int main(){
    int n;
    cout << "Enter the length : " << endl;
    cin >> n;

    vector<string> ans;
    
    int total = solve(0, 0, n, "", ans);

    cout << "Resultant set of parentheses are : " << endl;
    for(auto s : ans){
        cout << s << endl;
    }

    cout << "Total number is : " << total << endl;

    return 0;
}