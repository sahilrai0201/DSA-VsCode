// Converting decimal numbers into binary 

// TC = O(LOG2N) & SC = O(LOG2N) 

#include<bits/stdc++.h>
using namespace std;

// Function
string convert2binary(int n){
    if(n == 0) return "0";

    string res = "";

    while(n > 1){
        if(n % 2 == 1) res += '1';
        else res += '0';

        n = n / 2;
    }

    res += '1';

    reverse(res.begin(), res.end());
    return res;
}

int main(){
    int n;
    cout << "Enter the number : " << endl;
    cin >> n;

    string result = convert2binary(n);
    cout << "Conversion from decimal to binary number is : " << result << endl;

    return 0;
}