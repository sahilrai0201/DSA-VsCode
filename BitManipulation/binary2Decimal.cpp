// Binary to its decimal equivalent

// TC = O(LEN(X)) & SC = O(1)

#include<bits/stdc++.h>
using namespace std;

// function ->
int convert2decimal(string x){
    int n = x.length();
    int num = 0;
    int p2 = 1;

    for(int i = n - 1; i >= 0; i--){
        if(x[i] == '1'){
            num += p2;
        }
        p2 = p2 * 2;
    }

    return num;
}

int main(){
    string s;
    cout << "Enter the binary number : " << endl;
    cin >> s;

    int answer = convert2decimal(s);
    cout << "Decimal conversion of given binary number is : " << answer << endl;

    return 0;
}