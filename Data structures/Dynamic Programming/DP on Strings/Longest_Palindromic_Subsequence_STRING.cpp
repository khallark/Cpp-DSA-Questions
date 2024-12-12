#include <iostream>
#include <matrix.h>
using namespace std;

string lcs(string& s, string& t) {
    vector<vector<int>> dp(s.length() + 1, vector<int>(t.length() + 1));

    for(int s_length = 1; s_length <= s.length(); s_length++) {
        for(int t_length = 1; t_length <= t.length(); t_length++) {
            int ans;
            if(s[s_length - 1] == t[t_length - 1]) ans = dp[s_length - 1][t_length - 1] + 1;
            else ans = max(dp[s_length - 1][t_length], dp[s_length][t_length - 1]);
            dp[s_length][t_length] = ans;
        }
    }

    string ans = "";
    int i = s.length();
    int j = t.length();
    while(i > 0 && j > 0) {
        if(s[i - 1] == t[j - 1]) {
            ans += s[i - 1];
            i--;
            j--;
        }
        else {
            if(dp[i][j - 1] > dp[i - 1][j]) j--;
            else i--;
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

string longestPalindromeSubsequence(string s) {
    string t = s;
    reverse(t.begin(), t.end());
    return lcs(s, t);
}

int main() {
    string s = "abcdefgh";
    cout << longestPalindromeSubsequence(s);
    return 0;
}