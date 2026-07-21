// Word Break

#include<bits/stdc++.h>
using namespace std;

bool solve(int index, string &s, unordered_set<string> &st){
    if(index == (int) s.length()){
        return true;
    }

    string word = "";

    for(int end = index; end < (int) s.length(); end++){
        word += s[end];

        if(st.find(word) != st.end()){
            if(solve(end + 1, s, st)){
                return true;
            }
        }
    }

    return false;
}

bool wordBreak(string &s, vector<string> &dictionary){
    unordered_set<string> st(dictionary.begin(), dictionary.end());
    return solve(0, s, st);
}

int main(){
    string s;
    cout << "Enter the string : " << endl;
    cin >> s;

    int n;
    cout << "Enter the size of dictionary : " << endl;
    cin >> n;

    vector<string> dictionary;
    cout << "Enter the dictionary words : " << endl;

    string word;
    for(int i=0; i<n; i++){
        cin >> word;
        dictionary.push_back(word);
    }

    bool result = wordBreak(s, dictionary);

    cout << "Can we form s using strings from dictionary? : " << (result ? "True" : "False")<< endl;

    return 0;
}



// Output ->
// Enter the string : 
// ilike
// Enter the size of dictionary : 
// 3
// Enter the dictionary words : 
// i like gfg
// Can we form s using strings from dictionary? : True