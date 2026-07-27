// Longest Substring Without Repeating Characters

#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s){
    int n = s.length();

    unordered_map<char, int> lastIndex;

    int i = 0;
    int maxLen = 0;

    for(int j = 0; j < n; j++){
        if(lastIndex.count(s[j]) && lastIndex[s[j]] >= i){
            i = lastIndex[s[j]] + 1;
        }

        lastIndex[s[j]] = j;
        maxLen = max(maxLen, j - i + 1);
    }

    return maxLen;
}

int main(){
    string s;
    cout << "Enter the string : " << endl;
    cin >> s;

    int answer = lengthOfLongestSubstring(s);
    cout << "The length of longest substring without repeating characters is : " << answer << endl;

    return 0;
}



// Output ->
// Enter the string : 
// abcabcbb
// The length of longest substring without repeating characters is : 3