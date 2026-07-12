//String to Integer (atoi)

#include<bits/stdc++.h>
using namespace std;

int myAtoi(string &s){
    int n = s.length();

    int i = 0;

    while(i < n && s[i] == ' '){
        i++;
    }

    int sign = 1;
    while(i < n && (s[i] == '+' || s[i] == '-')){
        if(s[i] == '-'){
            sign = -1;
        }
        i++;
    }

    long long ans = 0;

    while(i < n && isdigit(s[i])){
        ans = ans * 10 + (s[i] - '0');

        if(sign * ans > INT_MAX) return INT_MAX;
        if(sign * ans < INT_MIN) return INT_MIN;

        i++;
    }

    return sign * ans;
}

int main(){
    string s;
    cout << "Enter the string : " << endl;
    getline(cin, s);

    int result = myAtoi(s);

    cout << "Given string can be written in integer format as : " << endl;

    cout << result << endl;

    return 0;
}