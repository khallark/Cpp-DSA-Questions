#include <iostream>
#include <vector>
using namespace std;
bool solve(int n, int k, vector<int> arr, vector<vector<int>> &dp) {
    if(k == 0) return true;
    if(n == 1) return arr[n - 1] == k;
    if(dp[n - 1][k - 1] != -1) return dp[n - 1][k - 1];

    bool notPick = solve(n - 1, k, arr, dp);
    bool pick = false;
    if(notPick || arr[n - 1] <= k) {
        pick = solve(n - 1, k - arr[n - 1], arr, dp);
    }
    
    return dp[n - 1][k - 1] = pick || notPick;
}
bool subsetSumToK1(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k, -1));
    return solve(n, k, arr, dp);
}


bool subsetSumToK2(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));
    for(int i = 0; i < n; i++) dp[i][0] = true;
    dp[0][arr[0]] = true;
    for(int ind = 1; ind < n; ind++) {
        for(int target = 1; target <= k; target++) {
            bool notTake = dp[ind - 1][target];
            bool take = false;
            if(arr[ind] <= target) take = dp[ind - 1][target - arr[ind]];
            dp[ind][target] = take | notTake;
        }
    }
    return dp[n - 1][k];
}
int main() {
    vector<int> arr = {2, 4, 1, 3};
    int n = arr.size();
    int k = 10;
    cout << subsetSumToK1(n, k, arr);
}