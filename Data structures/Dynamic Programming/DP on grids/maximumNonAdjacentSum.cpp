#include <iostream>
#include <vector>
using namespace std;

// DP with memoization (Recursion)
int solve_through_memoization(int index, vector<int>& nums, vector<int> &dp) {
    if(index == 0) {
        return nums[0];
    }
    if(index < 0) {
        return 0;
    }
    if(dp[index] != -1) {
        return dp[index];
    }

    int pick = nums[index] + solve_through_memoization(index - 2, nums, dp);
    int not_pick = 0 + solve_through_memoization(index - 1, nums, dp);

    return dp[index] = max(pick, not_pick);
}
int maximumNonAdjacentSum1(vector<int> &nums) {
    vector<int> dp(nums.size(), -1);
    return solve_through_memoization(nums.size() - 1, nums, dp);
}


// DP with tabulation (Iterations)
int maximumNonAdjacentSum2(vector<int> &nums) {
    vector<int> dp(nums.size() + 1);

    dp[0] = 0;
    dp[1] = nums[0];

    int index;
    for(index = 1; index < nums.size(); index++) {
        int pick = nums[index] + dp[index - 2 + 1];
        int not_pick = 0 + dp[index - 1 + 1];
        dp[index + 1] = max(pick, not_pick);
    }

    return dp[index];
}


// DP with Space Optimization
int maximumNonAdjacentSum3(vector<int> &nums) {
    int a = 0;
    int b = nums[0];

    int index;
    for(index = 1; index < nums.size(); index++) {
        int pick = nums[index] + a;
        int not_pick = 0 + b;
        a = b;
        b = max(pick, not_pick);
    }

    return b;
}


int main() {
    vector<int> nums = {1, 6, 3, 9, 2, 7, 0, 9};
    cout << maximumNonAdjacentSum1(nums) << endl;
    cout << maximumNonAdjacentSum2(nums) << endl;
    cout << maximumNonAdjacentSum3(nums) << endl;
    return 0;
}