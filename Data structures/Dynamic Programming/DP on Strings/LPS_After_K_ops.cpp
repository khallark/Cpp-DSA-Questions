#include <iostream>
#include <vector>
using namespace std;

/*
You are given a string s and an integer k.

In one operation, you can replace the character at any position with the next or previous letter in the alphabet (wrapping around so that 
'a' is after 'z'). For example, replacing 'a' with the next letter results in 'b', and replacing 'a' with the previous letter results in 
'z'. Similarly, replacing 'z' with the next letter results in 'a', and replacing 'z' with the previous letter results in 'y'.

Return the length of the longest palindromic subsequence of s that can be obtained after performing at most k operations.
*/

int cyclicDist(char a, char b) { 
    return min(26 - abs(a - b), abs(a - b));
}

int longestPalindromicSubsequence(string s, int ops) {
    int n = s.length();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(ops + 1, 0)));

    // Base case: Single character palindromes
    for (int i = 0; i < n; i++) {
        for (int k = 0; k <= ops; k++) {  // k starts from 0
            dp[i][i][k] = 1;
        }
    }

    // DP transition
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            for (int k = 0; k <= ops; k++) {
                dp[i][j][k] = max(dp[i + 1][j][k], dp[i][j - 1][k]);
                int cost = cyclicDist(s[i], s[j]);
                if (k >= cost) {
                    dp[i][j][k] = max(dp[i][j][k], 2 + dp[i + 1][j - 1][k - cost]);
                }
            }
        }
    }
    
    return dp[0][n - 1][ops];
}

int main() {
    string s = "aaazzz";
    int k = 4;
    cout << longestPalindromicSubsequence(s, k);
    return 0;
}