#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

// DP with Recursion (memoization)
int FrogJump_rec(int n, vector<int>& heights, vector<int>& dp) {
    if(n == 1) {
        return 0;
    }
    if(n <= 0) {
        return 10e5;
    }
    int a, b;

    if(dp[n - 1 - 1] != -1) a = dp[n - 1 - 1];
    else a = dp[n - 1 - 1] = FrogJump_rec(n - 1, heights, dp);
    if(dp[n - 2 - 1] != -1) b = dp[n - 2 - 1];
    else b = dp[n - 2 - 1] = FrogJump_rec(n - 2, heights, dp);

    int height_diff1 = fabs(heights[n - 1] - heights[n - 1 - 1]);
    int height_diff2 = fabs(heights[n - 1] - heights[n - 2 - 1]);

    return min(height_diff1 + a, height_diff2 + b);
}


// DP with iteration (tabulation)
int FrogJump_tab(int n, vector<int>& heights) {
    vector<int> dp(n + 1);
    dp[0] = 10e5;
    dp[1] = 0;

    for(int i = 2; i <= n; i++) {
        int height_diff1 = fabs(heights[i - 1] - heights[i - 1 - 1]);
        int height_diff2 = fabs(heights[i - 1] - heights[i - 2 - 1]);
        dp[i] = min(dp[i - 1] + height_diff1, dp[i - 2] + height_diff2);
    }

    return dp[n];
}


// DP with space optimisation [o(1) space complexity]
int FrogJump_so(int n, vector<int>& heights) {
    int a = 10e5;
    int b = 0;

    for(int i = 2; i <= n; i++) {
        int temp = b;
        int height_diff1 = fabs(heights[i - 1] - heights[i - 1 - 1]);
        int height_diff2 = fabs(heights[i - 1] - heights[i - 2 - 1]);
        b =  min(b + height_diff1, a + height_diff2);
        a = temp;
    }

    return b;
}

int main() {
    vector<int> heights = {30, 10, 60, 10, 60, 50};
    cout << FrogJump_so(3, heights);
    return 0;
}