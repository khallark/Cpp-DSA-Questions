#include <iostream>
#include <vector>
using namespace std;
int solve(vector<int> &denominations, vector<vector<int>> &dp, int target, int index) {
    if(index == 0) {
        return (target % denominations[index] == 0);
    }
    if(dp[index][target] != -1) return dp[index][target];

    int notTake = solve(denominations, dp, target, index - 1);
    int take = 0;
    if(denominations[index] <= target) take = solve(denominations, dp, target - denominations[index], index);

    return dp[index][target] = take + notTake;
}
long Coin_Combs_II_1(vector<int> &denominations, int n, int value) {
    vector<vector<int>> dp(n, vector<int>(value + 1, -1));
    return solve(denominations, dp, value, n - 1);
}

long Coin_Combs_II_2(vector<int> &denominations, int n, int value) {
    vector<vector<long>> dp(n, vector<long>(value + 1));

    for(int i = 0; i <= value; i++) if(i % denominations[0] == 0) dp[0][i] = 1;

    for(int index = 1; index < n; index++) {
        for(int target = 0; target <= value; target++) {
            long notTake = dp[index - 1][target];
            long take = 0;
            if(denominations[index] <= target) take = dp[index][target - denominations[index]];
            dp[index][target] = take + notTake;
        }
    }

    return dp[n - 1][value];
}

long Coin_Combs_II_3(vector<int> &denominations, int n, int value)
{
    vector<vector<long>> dp(2, vector<long>(value + 1));

    for(int i = 0; i <= value; i++) if(i % denominations[0] == 0) dp[0][i] = 1;

    for(int index = 1; index < n; index++) {
        for(int target = 0; target <= value; target++) {
            long notTake = dp[0][target];
            long take = 0;
            if(denominations[index] <= target) take = dp[1][target - denominations[index]];
            dp[1][target] = take + notTake;
        }
        dp[0] = dp[1];
    }

    return dp[0][value];
}

int main() {
    vector<int> denominations = {1, 2, 3};
    int n = denominations.size();
    int value = 4;
    cout << Coin_Combs_II_1(denominations, n, value) << endl;
    cout << Coin_Combs_II_2(denominations, n, value) << endl;
    cout << Coin_Combs_II_3(denominations, n, value);
}