//Reverse String 

#include<bits/stdc++.h>
using namespace std;

// void reverse(string &s){
//     int n = s.length();

//     int start = 0, end = n - 1;

//     while(start <= end){
//         swap(s[start++], s[end--]);
//     }
// }

void reverse(string &s){
    int n = s.length();

    stack<char> st;

    for(char ch : s){
        st.push(ch);
    }

    for(int i=0; i<n; i++){
        s[i] = st.top();
        st.pop();
    }
}

int main(){
    string s;
    cout << "Enter the string : " << endl;
    getline(cin, s);

    reverse(s);

    cout << "Reverse of the given string is : " << s << endl;

    return 0;
}