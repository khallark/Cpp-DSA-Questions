#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int solve(vector<int> &dp, int n) {
    if(n == 0) return 0;
    if(dp[n]) return dp[n];
    int b = n;
    int mini = INT_MAX;
    while(b) {
        int digit = b % 10;
        if(digit) mini = min(mini, solve(dp, n - digit));
        b /= 10;
    }
    return dp[n] = mini + 1;
}
int removeDigits1(int n) {
    vector<int> dp(n + 1, -1);
    return solve(dp, n);
}

int removeDigits2(int n) {
    if(n < 10) return 1;
    vector<int> dp(n + 1, 0);

    for(int i = 1; i < 10; i++) {
        dp[i] = 1;
    }

    for(int i = 10; i <= n; i++) {
        int b = i;
        int mini = INT_MAX;
        while(b) {
            int digit = b % 10;
            if(digit) mini = min(mini, dp[i - digit]);
            b /= 10;
        }
        dp[i] = mini + 1;
    }

    return dp[n];
}
int main() {
    int n;
    cin >> n;
    cout << removeDigits2(n);
    return 0;
}