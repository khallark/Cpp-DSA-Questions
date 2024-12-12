#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string longestPalindrome(string s) {
    string t = s;
    reverse(t.begin(), t.end());
    int n = s.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    int maxLength = 0;
    int endIndex = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if(dp[i][j] > maxLength && i - dp[i][j] == n - j) {
                    maxLength = dp[i][j];
                    endIndex = i - 1;
                }
            }
        }
    }
    return s.substr(endIndex - maxLength + 1, maxLength);
}

int main() {
    string s = "aacabdkacaa";
    cout << longestPalindrome(s) << endl;
    return 0;
}