// Letter Combinations of a Phone Number

#include<bits/stdc++.h>
using namespace std;

void solve(int index, string digit, string mapping[], string &output, vector<string> &ans){
    if(index >= (int) digit.length()){
        ans.push_back(output);
        return;
    }

    int number = digit[index] - '0';
    string value = mapping[number];

    for(int i = 0; i < (int) value.length(); i++){
        output.push_back(value[i]);
        solve(index + 1, digit, mapping, output, ans);
        output.pop_back();
    }
}

vector<string> phoneKeypad(string digit){
    vector<string> ans;
    if(digit.length() == 0) return ans;
    
    string output;
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    solve(0, digit, mapping, output, ans);

    return ans;
} 

int main(){
    string digit;
    cout << "Enter the digit : " << endl;
    getline(cin, digit);

    vector<string> result = phoneKeypad(digit);

    cout << "Resultant string for a digit in phone keypad is : " << endl; 
    for(auto s : result){
        cout << s << " ";
    }
    cout << endl;

    return 0;
}