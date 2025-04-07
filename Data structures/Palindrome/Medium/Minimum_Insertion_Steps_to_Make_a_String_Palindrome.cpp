#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
/*
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.
*/
class Solution {
public:
    vector<vector<int>> dp;
    int n;
    string s;
    int f(int l, int r) {
        if(l >= r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        if(s[l] == s[r]) return dp[l][r] = f(l + 1, r - 1);
        return dp[l][r] = 1 + min(f(l + 1, r), f(l, r - 1));
    }
    int minInsertions(string str) {
        n = str.length();
        s = str;
        dp.assign(n, vector<int>(n, -1));
        return f(0, n - 1);
    }
};

int main() {
    Solution s;
    cout << s.minInsertions("asdfghjklkjhgfddsa") << endl;
    return 0;
}