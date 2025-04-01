#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lcs(string& s, string& t) {
    vector<vector<int>> dp(2, vector<int>(t.length()));

    for(int s_length = 0; s_length < s.length(); s_length++) {
        for(int t_length = 0; t_length < t.length(); t_length++) {
            int ans;
            if(s[s_length] == t[t_length]) {
                ans = 1;
                if(s_length - 1 >= 0 && t_length - 1 >= 0) ans += dp[0][t_length - 1];
            }
            else {
                int a = s_length - 1 >= 0 ? dp[0][t_length] : 0;
                int b = t_length - 1 >= 0 ? dp[1][t_length - 1] : 0;
                ans = max(a, b);
            }
            dp[1][t_length] = ans;
        }
        dp[0] = dp[1];
    }

    return dp[0][t.length() - 1];
}

int longestPalindromeSubsequence(string s) {
    string t = s;
    reverse(t.begin(), t.end());
    return lcs(s, t);
}

int main() {
    string s = "abca";
    cout << longestPalindromeSubsequence(s);
    return 0;
}