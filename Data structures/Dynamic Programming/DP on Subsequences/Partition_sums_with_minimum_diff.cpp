#include <iostream>
#include <vector>
#include <cmath>
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

int minSubsetSumDifference(vector<int>& arr, int n) {
	int sum = 0;
    for(auto i : arr) {
        sum += i;
    }
    int target = sum / 2;
    int ans = sum - target;
    while(true) {
        if(subsetSumToK(n, target, arr)) {
            ans = sum - target;
            break;
        }
        target++;
    }
    return fabs(ans - (sum - ans));
}

int main() {
    vector<int> arr = {3, 1, 5, 2, 8};
    int size = arr.size();
    cout << minSubsetSumDifference(arr, size);
    return 0;
}