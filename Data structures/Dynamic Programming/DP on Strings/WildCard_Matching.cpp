#include <iostream>
#include <vector>
using namespace std;
bool wildcardMatching(string pattern, string text) {
    int m = pattern.size();
    int n = text.size();
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    int preVal, temp;
    for(int i = 1; i <= m; i++) {
        preVal = dp[0];
        if(pattern[i - 1] != '*') dp[0] = false;
        for(int j = 1; j <= n; j++) {
            temp = preVal;
            preVal = dp[j];
            if(pattern[i - 1] == '*') dp[j] = dp[j] | dp[j - 1];
            else if(pattern[i - 1] == '?') dp[j] = temp;
            else if(pattern[i - 1] != text[j - 1]) dp[j] = false;
            else dp[j] = temp;
        }
    }
    return dp[n];
}

int main() {
    string pattern = "yhn";
    string text = "yhn";
    cout << wildcardMatching(pattern, text) << endl;
    return 0;
}