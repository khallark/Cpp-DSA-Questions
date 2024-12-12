#include <iostream>
#include <vector>
#include <matrix.h>
using namespace std;

// In this question, you can do atmost 2 buy-sell transactions, such that the profit can be maxed.


int solve(vector<int>& prices, vector<vector<vector<int>>>& dp, int day, int buy, int cap) {
    if(day == prices.size()) return 0;
    if(cap == 0) return 0;

    if(dp[day][buy][cap] != -1) return dp[day][buy][cap];

    if(buy) {
        dp[day][buy][cap] = max(
            -prices[day] + solve(prices, dp, day + 1, 0, cap),
            0 + solve(prices, dp, day + 1, 1, cap)
        );
    }
    else {
        dp[day][buy][cap] = max(
            prices[day] + solve(prices, dp, day + 1, 1, cap - 1),
            0 + solve(prices, dp, day + 1, 0, cap)
        );
    }

    return dp[day][buy][cap];
}
int maxProfit1(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    return solve(prices, dp, 0, 1, 2);
}


int maxProfit2(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3)));
    
    for(int day = n - 1; day >= 0; day--) {
        for(int buy = 0; buy < 2; buy++) {
            for(int cap = 1; cap <= 2; cap++) {
                if(buy) {
                    dp[day][buy][cap] = max(
                        -prices[day] + dp[day + 1][0][cap],
                        0 + dp[day + 1][1][cap]
                    );
                }
                else {
                    dp[day][buy][cap] = max(
                        prices[day] + dp[day + 1][1][cap - 1],
                        0 + dp[day + 1][0][cap]
                    );
                }
            }
        }
    }

    return dp[0][1][2];
}


int main() {
    vector<int> prices = {3,3,5,0,0,3,1,4};
    cout << maxProfit2(prices);
}