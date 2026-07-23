// Valid Parentheses

#include<bits/stdc++.h>
using namespace std;

bool isValid(string &s){
    stack<char> st;
    st.push('0');

    for(char b : s){
        char t = st.top();

        if((b == ')' && t == '(') || (b == '}' && t == '{') || (b == ']' && t == '[')){
            st.pop();
        }
        else{
            st.push(b);
        }
    }

    return st.top() == '0';
}

int main(){
    string s;
    cout << "Enter the string of parentheses : " << endl;
    cin >> s;

    bool result = isValid(s);
    cout << "Is the given string contains valid set of parentheses? : " << endl;
    cout << result;

    return 0;
}


// Output ->
// Enter the string of parentheses : 
// (){}[]
// Is the given string contains valid set of parentheses? : 
// 1