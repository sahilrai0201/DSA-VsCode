// String Compression

#include<bits/stdc++.h>
using namespace std;

vector<string> stringComp(vector<string> &chars){
    int n = chars.size();
    vector<string> ans;

    int count = 1;

    for(int i=0; i<n-1; i++){
        if(chars[i] == chars[i+1]){
            count++;
        }
        else{
            ans.push_back(chars[i]);
            ans.push_back(to_string(count));
            count = 1;
        }
    }

    ans.push_back(chars[n-1]);
    ans.push_back(to_string(count));

    return ans;
}

int main(){
    int n;
    cout << "Enter the size of string array : " << endl;
    cin >> n;

    vector<string> chars(n);

    cout << "Enter the chars of string : " << endl;
    for(int i=0; i<n; i++){
        cin >> chars[i];
    }

    vector<string> result = stringComp(chars);
    
    cout << "Resultant vector of string after string compression is : " << endl;
    for(auto str : result){
        cout << str;
    }

    return 0;
}