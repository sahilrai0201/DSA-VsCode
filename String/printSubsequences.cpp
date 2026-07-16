// All Subsequences of a String

#include<bits/stdc++.h>
using namespace std;

void solve(int index, string &s, string curr, vector<string> &ans){
    if(index == (int)s.length()){
        ans.push_back(curr);
        return;
    }

    //include
    solve(index + 1, s, curr + s[index], ans);

    //exclude
    solve(index + 1, s, curr, ans);
}

vector<string> powerSet(string& s){
    vector<string> ans;

    solve(0, s, "", ans);
    sort(ans.begin(), ans.end());

    return ans;
}

int main(){
    string s;
    cout << "Enter the string : " << endl;
    getline(cin, s);

    vector<string> result = powerSet(s);

    cout << "All subsequences of the given string are : " << endl;
    for(auto s : result){
        cout << "\"" <<  s << "\"" << " ";
    }
    cout << endl;

    return 0;
}