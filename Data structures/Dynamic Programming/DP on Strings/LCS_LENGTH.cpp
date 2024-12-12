#include <iostream>
#include <vector>
using namespace std;

int solve(string s, string t, vector<vector<int>> &dp, int s_length, int t_length) {
    if(s_length < 0 || t_length < 0) {
        return 0;
    }
    if(dp[s_length][t_length] != -1) return dp[s_length][t_length];

    int ans;
    if(s[s_length] == t[t_length]) ans = 1 + solve(s, t, dp, s_length - 1, t_length - 1);
    else ans = max(solve(s, t, dp, s_length - 1, t_length), solve(s, t, dp, s_length, t_length - 1));

    return dp[s_length][t_length] = ans;
}
int lcs1(string s, string t) {
    vector<vector<int>> dp(s.length(), vector<int>(t.length(), -1));
    return solve(s, t, dp, s.length() - 1 , t.length() - 1);
}

int lcs2(string s, string t) {
    vector<vector<int>> dp(s.length(), vector<int>(t.length()));

    for(int s_length = 0; s_length < s.length(); s_length++) {
        for(int t_length = 0; t_length < t.length(); t_length++) {
            int ans;
            if(s[s_length] == t[t_length]) {
                ans = 1;
                if(s_length - 1 >= 0 && t_length - 1 >= 0) ans += dp[s_length - 1][t_length - 1];
            }
            else {
                int a = s_length - 1 >= 0 ? dp[s_length - 1][t_length] : 0;
                int b = t_length - 1 >= 0 ? dp[s_length][t_length - 1] : 0;
                ans = max(a, b);
            }
            dp[s_length][t_length] = ans;
        }
    }

    return dp[s.length() - 1][t.length() - 1];
}

int lcs3(string s, string t) {
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

int main() {
    string s = "adebc";
    string t = "dcadb";
    cout << lcs2(s, t);
    return 0;
}