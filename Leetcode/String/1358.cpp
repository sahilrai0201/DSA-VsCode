// Number of Substrings Containing All Three Characters

#include<bits/stdc++.h>
using namespace std;

int totalSubstrings(string &s){
    int n = s.length();

    int l = 0; 
    int ans = 0;

    vector<int> cnt(3, 0);

    for(int r=0; r<n; r++){
        cnt[s[r] - 'a']++;

        while(cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0){
            ans += (n-r);

            cnt[s[l] - 'a']--;
            l++;
        }
    }

    return ans;
}

int main(){
    string s;
    cout << "Enter the string : " << endl;
    getline(cin, s);

    int result = totalSubstrings(s);
    cout << "Total substrings containg all three a, b & c is : " << endl;
    cout << result << endl;

    
    return 0;
}