//Given a string s, sort it in decreasing order based on the frequency of the characters. 
//The frequency of a character is the number of times it appears in the string.
//Return the sorted string. If there are multiple answers, return any of them.

#include<bits/stdc++.h>
using namespace std;

static bool cmp(pair<char, int> &a, pair<char, int> &b){
    return a.second > b.second;
}

string freqSort(string &s){
    string st = "";

    unordered_map<char, int> mp;

    for(auto ch : s){
        mp[ch]++;
    }

    vector<pair<char, int>> vec;

    for(auto it : mp){
        vec.push_back(it);
    }

    sort(vec.begin(), vec.end(), cmp);

    for(auto ans : vec){
        for(int i=0; i<ans.second; i++){
            st += ans.first;
        }
    }

    return st;
}

int main(){
    string s;
    cout << "Enter the input string : " << endl;
    getline(cin, s);

    string result = freqSort(s);

    cout << "Sorted order of string s based on freq count is : " << result << endl;

    return 0;
}