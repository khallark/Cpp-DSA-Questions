#include <iostream>
#include <vector>
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr) {
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

bool canPartition(vector<int> &arr, int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum & 1 ? false : subsetSumToK(n, sum / 2, arr);
}

int main() {
    vector<int> arr = {2, 4, 1, 8};
    int size = arr.size();
    cout << canPartition(arr, size);
}