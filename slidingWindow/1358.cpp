// Number of Substrings Containing All Three Characters

#include<bits/stdc++.h>
using namespace std;

int countSubstrings(string &s){
    int n = s.length();

    int l = 0;
    int ans = 0;

    vector<int> cnt(3, 0);

    for(int r = 0; r < n; r++){
        cnt[s[r] - 'a']++;

        while(cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0){
            ans += (n - r);

            cnt[s[l] - 'a']--;
            l++;
        }
    }

    return ans;
}

int main(){
    string s;
    cout << "Enter the string : " << endl;
    cin >> s;

    int result = countSubstrings(s);

    cout << "Number of substrings containig all three characters are : " << result << endl;

    return 0;
}





// Output ->
// Enter the string : 
// abcabc
// Number of substrings containig all three characters are : 10