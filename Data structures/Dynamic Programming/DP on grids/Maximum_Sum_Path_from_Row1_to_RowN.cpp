#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Recursion with DP (Memoization)
// TC → O(m * n)
// TC → O(m * n)

int solve(int m, int n, vector<vector<int>> &matrix, vector<vector<int>> &dp, int i, int j) {
    if(j < 0 || j >= n) {
        return INT_MIN;
    }
    if(i == m - 1) {
        return dp[i][j] = matrix[i][j];
    }
    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    int left = solve(m, n, matrix, dp, i + 1, j - 1);
    int straight = solve(m, n, matrix, dp, i + 1, j);
    int right = solve(m, n, matrix, dp, i + 1, j + 1);

    return dp[i][j] = matrix[i][j] + max(left, max(straight, right));
}
int getMaxPathSum1(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    int ans = INT_MIN;
    for(int j = 0; j < n; j++) {
        ans = max(ans, solve(m, n, matrix, dp, 0, j));
    }
    return ans;
}


// Iteration with DP (Tabulation)
// TC → O(m * n)
// TC → O(m * n)

int getMaxPathSum2(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n));

    for(int i = m - 1; i >= 0; i--) {
        for(int j = 0; j < n; j++) {
            if(i == m - 1) {
                dp[i][j] = matrix[i][j];
            }
            else {
                int left = (j - 1 < 0) ? INT_MIN : dp[i + 1][j - 1];
                int straight = dp[i + 1][j];
                int right = (j + 1 >= n) ? INT_MIN : dp[i + 1][j + 1];

                dp[i][j] = matrix[i][j] + max(left, max(straight, right));
            }
        }
    }

    int ans = INT_MIN;
    for(int i = 0; i < n; i++) {
        ans = max(ans, dp[0][i]);
    }

    return ans;
}


// Space Optmization
// TC → O(m * n)
// TC → O(n)
int getMaxPathSum3(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(2, vector<int>(n));

    for(int i = m - 1; i >= 0; i--) {
        for(int j = 0; j < n; j++) {
            if(i == m - 1) {
                dp[0][j] = matrix[i][j];
            }
            else {
                int left = (j - 1 < 0) ? INT_MIN : dp[1][j - 1];
                int straight = dp[1][j];
                int right = (j + 1 >= n) ? INT_MIN : dp[1][j + 1];

                dp[0][j] = matrix[i][j] + max(left, max(straight, right));
            }
        }
        for(int j = 0; j < n; j++) {
            dp[1][j] = dp[0][j];
        }
    }

    int ans = INT_MIN;
    for(int i = 0; i < n; i++) {
        ans = max(ans, dp[1][i]);
    }

    return ans;
}

int main() {
    vector<vector<int>> matrix = {
        {10, 10, 2, -13, 20, 4},
        {1, -9, -81, 30, 2, 5},
        {0, 10, 4, -79, 2, -10},
        {1, -5, 2, 20, -11, 4}
    };
    cout << getMaxPathSum1(matrix) << endl;
    cout << getMaxPathSum2(matrix) << endl;
    cout << getMaxPathSum3(matrix) << endl;
    return 0;
}