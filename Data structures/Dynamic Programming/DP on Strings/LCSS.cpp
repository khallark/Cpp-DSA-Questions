#include <iostream>
#include <vector>

using namespace std;

int lcs(string s, string t) {
    vector<vector<int>> dp(s.length(), vector<int>(t.length()));

    for(int s_length = 0; s_length < s.length(); s_length++) {
        for(int t_length = 0; t_length < s.length(); t_length++) {
            int ans;
            if(s[s_length] == t[t_length]) {
                ans = 1;
                if(s_length - 1 >= 0 && t_length - 1 >= 0) ans += dp[s_length - 1][t_length - 1];
                dp[s_length][t_length] = ans;
            }
            else {
                dp[s_length][t_length] = 0;
            }
        }
    }

    int ans = INT_MIN;
    for(auto i : dp) {
        for(auto j : i) {
            ans = max(ans, j);
        }
    }

    return ans;
}

int main() {
    string s = "bcdeabcd";
    string t = "abcdfbcd";
    cout << lcs(s, t);
    return 0;
}