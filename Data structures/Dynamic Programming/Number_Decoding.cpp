#include <iostream>
#include <vector>
using namespace std;
int numDecodings(string s) {
    int n = s.length();
    vector<int> dp(n + 1);
    dp[0] = 1;
    if(s[0] > '0') dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        int ways = 0;
        if(s[i - 1] > '0') ways += dp[i - 1];
        int num = ((s[i - 2] -  48) * 10 + (s[i - 1] - 48));
        if(s[i - 2] != '0' && num > 0 && num <= 26) ways += dp[i - 2];
        dp[i] = ways;
    }
    return dp[n];
}
int main() {
    string code = "12673451";
    cout << numDecodings(code) << endl;
    return 0;
}