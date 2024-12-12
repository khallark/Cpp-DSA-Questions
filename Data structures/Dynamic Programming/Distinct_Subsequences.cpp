#include <iostream>
#include <vector>
using namespace std;

int n, m;
int f(string& s, string& t, vector<vector<int>>& dp, int i, int j) {
    if(i > n) {
        if(j > m) return 1;
        return 0;
    }
    else if(j > m) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    if(s[i - 1] == t[j - 1]) {
        return dp[i][j] = f(s, t, dp, i + 1, j + 1) + f(s, t, dp, i + 1, j);
    }
    return dp[i][j] = f(s, t, dp, i + 1, j);
}
int numDistinct(string s, string t) {
    n = s.length(), m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return f(s, t, dp, 1, 1);
}

int main() {
    string s = "rabbbit", t = "rabbit";
    cout << numDistinct(s, t);
    return 0;
}