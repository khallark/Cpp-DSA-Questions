#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &weight, vector<int> &value, int index, int maxWeight, vector<vector<int>> &dp) {
    if(index == 0) return value[0] * (maxWeight / weight[0]);
    if(dp[index][maxWeight] != -1) return dp[index][maxWeight];
    int notTake =  solve(weight, value, index - 1, maxWeight, dp);
    int take = 0;
    if(weight[index] <= maxWeight) take = value[index] + solve(weight, value, index, maxWeight - weight[index], dp);

    return dp[index][maxWeight] = max(take, notTake);
}

int knapsack1(vector<int> &weight, vector<int> &value, int n, int maxWeight_) {
    vector<vector<int>> dp(n, vector<int>(maxWeight_ + 1, -1));
    return solve(weight, value, n - 1, maxWeight_, dp);
}

int knapsack2(vector<int> &weight, vector<int> &value, int n, int maxWeight_) {
    vector<vector<int>> dp(n, vector<int>(maxWeight_ + 1));
    for(int i = 0; i <= maxWeight_; i++) {
        dp[0][i] = value[0] * (i / weight[0]);
    }

    for(int index = 1; index < n; index++) {
        for(int maxWeight = 0; maxWeight <= maxWeight_; maxWeight++) {
            int notTake =  dp[index - 1][maxWeight];
            int take = 0;
            if(weight[index] <= maxWeight) take = value[index] + dp[index][maxWeight - weight[index]];
            dp[index][maxWeight] = max(take, notTake);
        }
    }

    return dp[n - 1][maxWeight_];
}

int knapsack3(vector<int> &weight, vector<int> &value, int n, int maxWeight_) {
    vector<vector<int>> dp(2, vector<int>(maxWeight_ + 1));
    for(int i = 0; i <= maxWeight_; i++) {
        dp[0][i] = value[0] * (i / weight[0]);
    }

    for(int index = 1; index < n; index++) {
        for(int maxWeight = 0; maxWeight <= maxWeight_; maxWeight++) {
            int notTake =  dp[0][maxWeight];
            int take = 0;
            if(weight[index] <= maxWeight) take = value[index] + dp[1][maxWeight - weight[index]];
            dp[1][maxWeight] = max(take, notTake);
        }
        dp[0] = dp[1];
    }

    return dp[0][maxWeight_];
}

int knapsack4(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<int> dp(w + 1);
    for(int i = 0; i <= w; i++) {
        dp[i] = profit[0] * (i / weight[0]);
    }

    for(int index = 1; index < n; index++) {
        for(int maxWeight = 0; maxWeight <= w; maxWeight++) {
            int notTake =  dp[maxWeight];
            int take = 0;
            if(weight[index] <= maxWeight) take = profit[index] + dp[maxWeight - weight[index]];
            dp[maxWeight] = max(take, notTake);
        }
    }

    return dp[w];
}

int main() {
    vector<int> value = {5, 11, 13};
    vector<int> weight = {2, 4, 6};
    int n = weight.size();
    int maxWeight = 10;
    cout << knapsack3(weight, value, n, maxWeight);
    return 0;
}