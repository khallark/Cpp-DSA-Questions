#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &price, vector<vector<int>> &dp, int index, int length) {
    if(index == 0) return price[0] * length;
    if(dp[index][length] != -1) return dp[index][length];

    int notTake = solve(price, dp, index - 1, length);
    int take = 0;
    if(length >= index + 1) take = price[index] + solve(price, dp, index, length - index - 1);

    return dp[index][length] = max(take, notTake);
}
int cutRod1(vector<int> &price, int n) {
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return solve(price, dp, n - 1, n);
}

int cutRod2(vector<int> &price, int n) {
    vector<vector<int>> dp(n, vector<int>(n + 1));

    for(int i = 0; i <= n; i++) {
        dp[0][i] = i * price[0];
    }

    for(int index = 1; index < n; index++) {
        for(int length = 0; length <= n; length++) {
            int notTake = dp[index - 1][length];
            int take = 0;
            if(length >= index + 1) take = price[index] + dp[index][length - index - 1];
            dp[index][length] = max(take, notTake);
        }
    }

    return dp[n - 1][n];
}

int cutRod3(vector<int> &price, int n) {
    vector<int> dp(n + 1);

    for(int i = 0; i <= n; i++) {
        dp[i] = i * price[0];
    }

    for(int index = 1; index < n; index++) {
        for(int length = 0; length <= n; length++) {
            int notTake = dp[length];
            int take = 0;
            if(length >= index + 1) take = price[index] + dp[length - index - 1];
            dp[length] = max(take, notTake);
        }
    }

    return dp[n];
}
int main() {
    vector<int> price = {3, 5, 8, 9, 10, 17, 17, 20};
    cout << cutRod3(price, price.size());
    return 0;
}