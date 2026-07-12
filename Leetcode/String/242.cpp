//Given two strings s and t, return true if t is an anagram of s, and false otherwise.

#include<bits/stdc++.h>
using namespace std;

bool anagram(string &s, string &t){
    if(s.length() != t.length()){
        return false;
    }

    vector<int> freq(26, 0);

    for(int i=0; i<(int)s.length(); i++){
        freq[s[i] - 'a']++;
        freq[t[i] - 'a']--;
    }

    for(int count : freq){
        if(count != 0){
            return false;
        }
    }

    return true;
}

int main(){
    string s;
    cout << "Enter the string s : " << endl;
    getline(cin, s);

    string t;
    cout << "Enter the string t : " << endl;
    getline(cin, t);

    bool result = anagram(s, t);

    cout << boolalpha << result << endl;

    return 0;
}