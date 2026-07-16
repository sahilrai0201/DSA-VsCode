// Sum of Beauty of All Substrings

#include<bits/stdc++.h>
using namespace std;

int beautySum(string &s){
    int n = s.length();
    int ans = 0;

    for(int i=0; i<n; i++){
        vector<int> freq(26, 0);

        for(int j=i; j<n; j++){
            freq[s[j] - 'a']++;

            int maxfreq = 0;
            int minfreq = INT_MAX;

            for(int k=0; k<26; k++){
                if(freq[k] > 0){
                    maxfreq = max(maxfreq, freq[k]);
                    minfreq = min(minfreq, freq[k]);
                }
            }
            ans += (maxfreq - minfreq);
        }
    }
    return ans;
}

int main(){
    string s;
    cout << "Enter the string : " << endl;
    getline(cin, s);

    int result = beautySum(s);

    cout << "Beauty sum for the givenm string is : " << result << endl;

    return 0;
}