//Given two strings s and goal, return true if and only if s can become goal after some 
//number of shifts on s.
//A shift on s consists of moving the leftmost character of s to the rightmost position.
//For example, if s = "abcde", then it will be "bcdea" after one shift.

#include<bits/stdc++.h>
using namespace std;

//TC = O(N) ------------------------>
bool rotate(string &s, string &goal){
    if(s.length() != goal.length()){
        return false;
    }

    string temp = s + s;

    return temp.find(goal) != string::npos;
}

//TC = O(N*N) -------------------------->
// bool rotate(string &s, string &goal){
//     if(s.length() != goal.length()){
//         return false;
//     }

//     for(int i=0; i<(int)s.length(); i++){
//         if(s == goal){
//             return true;
//         }
//         char ch = s[0];
//         s = s.substr(1) + ch;
//     }

//     return false;
// }

int main(){
    string s;
    cout << "Enter the string s : " << endl;
    // cin >> s;
    getline(cin, s);

    string goal;
    cout << "Enter the string goal : " << endl;
    getline(cin, goal);

    bool result = rotate(s, goal);

    // cout << (result ? "True" : "False") << endl;
    cout << boolalpha << result << endl;

    return 0;
}

// input : s = abcde && goal = cdeab