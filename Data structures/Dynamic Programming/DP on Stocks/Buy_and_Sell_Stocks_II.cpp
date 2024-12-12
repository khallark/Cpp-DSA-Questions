#include <iostream>
#include <vector>
#include <matrix.h>
using namespace std;


// In this question, you can do multiple (buy-sell) transactions, such that the profit can be maxed.


long solve(vector<long>& prices, vector<vector<long>>& dp, int day, int buy) {
    if(day == prices.size()) return 0;
    if(dp[day][buy] != -1) return dp[day][buy];

    if(buy) {
        dp[day][buy] = max(
            -prices[day] + solve(prices, dp, day + 1, 0),
            0 + solve(prices, dp, day + 1, 1)
        );
    }
    else {
        dp[day][buy] = max(
            prices[day] + solve(prices, dp, day + 1, 1),
            0 + solve(prices, dp, day + 1, 0)
        );
    }

    return dp[day][buy];
}

long getMaximumProfit1(vector<long> &prices) {
    int n = prices.size();
    vector<vector<long>> dp(n, vector<long>(2, -1));
    return solve(prices, dp, 0, 1);
}

long getMaximumProfit2(vector<long> &prices) {
    int n = prices.size();
    vector<vector<long>> dp(n + 1, vector<long>(2));

    for(int day = n - 1; day >= 0; day--) {
        for(int buy = 0; buy < 2; buy++) {
            if(buy) {
                dp[day][buy] = max(
                    -prices[day] + dp[day + 1][0],
                    0 + dp[day + 1][1]
                );
            }
            else {
                dp[day][buy] = max(
                    prices[day] + dp[day + 1][1],
                    0 + dp[day + 1][0]
                );
            }
        }
    }
    cout << dp << endl;
    return dp[0][1];
}
int main() {
    vector<long> prices = {7, 1, 5, 3, 6, 4};
    cout << getMaximumProfit2(prices) << endl;
    return 0;
}