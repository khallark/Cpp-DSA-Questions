#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &weight, vector<int> &value, int index, int maxWeight, vector<vector<int>> &dp) {
    if(index == 0) return (weight[0] <= maxWeight) ? value[0] : 0;
    if(dp[index][maxWeight] != -1) return dp[index][maxWeight];
    int notTake =  solve(weight, value, index - 1, maxWeight, dp);
    int take = 0;
    if(weight[index] <= maxWeight) take = value[index] + solve(weight, value, index - 1, maxWeight - weight[index], dp);

    return dp[index][maxWeight] = max(take, notTake);
}

int knapsack1(vector<int> &weight, vector<int> &value, int n, int maxWeight_) {
    vector<vector<int>> dp(n, vector<int>(maxWeight_ + 1, -1));
    return solve(weight, value, n - 1, maxWeight_, dp);
}

int knapsack2(vector<int> &weight, vector<int> &value, int n, int maxWeight_) {
    vector<vector<int>> dp(n, vector<int>(maxWeight_ + 1));

    for (int maxWeight = 0; maxWeight <= maxWeight_; maxWeight++) {
        if (weight[0] <= maxWeight) {
            dp[0][maxWeight] = value[0];
        }
    }

    for(int index = 1; index < n; index++) {
        for(int maxWeight = 1; maxWeight <= maxWeight_; maxWeight++) {
            int notTake =  dp[index - 1][maxWeight];
            int take = 0;
            if(weight[index] <= maxWeight) take = value[index] + dp[index - 1][maxWeight - weight[index]];
            dp[index][maxWeight] = max(take, notTake);
        }
    }

    return dp[n - 1][maxWeight_];
}

int knapsack3(vector<int> &weight, vector<int> &value, int n, int maxWeight_) {
    vector<vector<int>> dp(2, vector<int>(maxWeight_ + 1));
    
    for (int maxWeight = 0; maxWeight <= maxWeight_; maxWeight++) {
        if (weight[0] <= maxWeight) {
            dp[0][maxWeight] = value[0];
        }
    }

    for(int index = 1; index < n; index++) {
        for(int maxWeight = 1; maxWeight <= maxWeight_; maxWeight++) {
            int notTake =  dp[0][maxWeight];
            int take = 0;
            if(weight[index] <= maxWeight) take = value[index] + dp[0][maxWeight - weight[index]];
            dp[1][maxWeight] = max(take, notTake);
        }
        dp[0] = dp[1];
    }

    return dp[0][maxWeight_];
}

int main() {
    vector<int> weight = {1, 2, 4, 5};
    vector<int> value = {5, 4, 8, 6};
    int n = weight.size();
    int maxWeight = 5;
    cout << knapsack3(weight, value, n, maxWeight);
    return 0;
}