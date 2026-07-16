// Consecutive 1's not allowed

#include<bits/stdc++.h>
using namespace std;

int solve(int index, int n, bool prevOne, string curr){
    if(index == n){
        cout << curr << " ";
        return 1;
    }

    int count = 0;

    count += solve(index + 1, n, false, curr + '0');

    if(!prevOne){
        count += solve(index + 1, n, true, curr + '1');
    }

    return count;
}

int countString(int n){
    return solve(0, n, false, "");
}

int main(){
    int n;
    cout << "Enter the length : " << endl;
    cin >> n;

    int result = countString(n);

    cout << endl;
    cout << "Total number of such possible strings are : " << result << endl;

    return 0;
}