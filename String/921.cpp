// Minimum add to make parentheses valid

#include<bits/stdc++.h>
using namespace std;

int minAdd(string &s){
    stack<int> st;

    for(char &ch : s){
        if(ch == '('){
            st.push(ch);
        }
        else{
            // ch == ')'
            if(!st.empty() && st.top() == '('){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
    }

    return st.size();
}

int main(){
    string s;
    cout << "Enter the string : " << endl;
    cin >> s;

    int answer = minAdd(s);
    cout << "Minimum additions required to make string valid is : " << answer << endl;

    return 0;
}



// Output ->
// Enter the string : 
// ())
// Minimum additions required to make string valid is : 1