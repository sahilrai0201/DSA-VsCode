//Given a string s, return the longest palindromic substring in s.

#include<bits/stdc++.h>
using namespace std;

void expand(string &s, int left, int right, int &start, int &maxLen){
    int n = s.length();

    while(left >= 0 && right < n && s[left] == s[right]){
        int currLen = right - left + 1;

        if(currLen > maxLen){
            maxLen = currLen;
            start = left;
        }

        left--;
        right++;
    }
}

string palindrome(string s){
    int n = s.length();

    int start = 0, maxLen = 1;

    for(int i=0; i<n; i++){
        expand(s, i, i, start, maxLen);
        expand(s, i, i+1, start, maxLen);
    }

    return s.substr(start, maxLen);
}

int main(){
    string s;
    cout << "Enter the string : " << endl;
    getline(cin, s);

    string result = palindrome(s);
    cout << "Longest palindromic substring is : " << result << endl;
    
    return 0;
}