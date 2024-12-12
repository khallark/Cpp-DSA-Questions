#include <iostream>
#include <vector>
using namespace std;

int solve(string s1, string s2, vector<vector<int>> &dp, int i, int j) {
    if(i == 0) return j;
    if(j == 0) return i;
    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i - 1] == s2[j - 1]) return dp[i][j] = solve(s1, s2, dp, i - 1, j - 1);

    int insertion = 1 + solve(s1, s2, dp, i - 1, j);
    int replacement = 1 + solve(s1, s2, dp, i - 1, j - 1);
    int deletion = 1 + solve(s1, s2, dp, i, j - 1);
    return dp[i][j] = min(insertion, min(replacement, deletion));
}
int minimum_steps_to_convert_stringA_to_stringB_1(string str1, string str2) {
    vector<vector<int>> dp(str1.length() + 1, vector<int>(str2.length() + 1, -1));
    return solve(str1, str2, dp, str1.length(), str2.length());
}



int minimum_steps_to_convert_stringA_to_stringB_2(string s1, string s2) {
    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1));

    for(int i = 0; i <= s1.length(); i++) dp[i][0] = i;
    for(int i = 0; i <= s2.length(); i++) dp[0][i] = i;

    for(int i = 1; i <= s1.length(); i++) {
        for(int j = 1; j <= s2.length(); j++) {
            if(s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                int insertion = 1 + dp[i - 1][j];
                int replacement = 1 + dp[i - 1][j - 1];
                int deletion = 1 + dp[i][j - 1];
                dp[i][j] = min(insertion, min(replacement, deletion));
            }
        }
    }

    return dp[s1.length()][s2.length()];
}



int minimum_steps_to_convert_stringA_to_stringB_3(string s1, string s2) {
    vector<vector<int>> dp(2, vector<int>(s2.length() + 1));

    for(int i = 0; i <= s2.length(); i++) dp[0][i] = i;

    for(int i = 1; i <= s1.length(); i++) {
        dp[1][0] = i;
        for(int j = 1; j <= s2.length(); j++) {
            if(s1[i - 1] == s2[j - 1]) {
                dp[1][j] = dp[0][j - 1];
            }
            else {
                int insertion = 1 + dp[0][j];
                int replacement = 1 + dp[0][j - 1];
                int deletion = 1 + dp[1][j - 1];
                dp[1][j] = min(insertion, min(replacement, deletion));
            }
        }
        dp[0] = dp[1];
    }

    return dp[0][s2.length()];
}



int main() {
    string str1 = "intention";
    string str2 = "execution";
    cout << minimum_steps_to_convert_stringA_to_stringB_3(str1, str2);
    return 0;
}