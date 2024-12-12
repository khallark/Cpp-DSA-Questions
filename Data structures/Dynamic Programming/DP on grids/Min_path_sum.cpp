#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Recursion with DP (Memoization)
// TC → O(m * n)
// TC → O(m * n)
int solve(vector<vector<int>> &grid, vector<vector<int>> &dp, int m, int n, int p1, int p2) {
    if(p1 >= m || p2 >= n) {
        return INT_MAX;
    }
    if(p1 == m - 1 && p2 == n - 1) {
        return grid[p1][p2];
    }
    if(dp[p1][p2] > 0) {
        return dp[p1][p2];
    }

    int down = solve(grid, dp, m, n, p1 + 1, p2);
    int right = solve(grid, dp, m, n, p1, p2 + 1);

    return dp[p1][p2] = grid[p1][p2] +  min(down, right);
}
int minSumPath1(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    return solve(grid, dp, m, n, 0, 0);
}


// Iteration with DP (Tabulation)
// TC → O(m * n)
// TC → O(m * n)
int minSumPath2(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[m - 1][n - 1] = grid[m - 1][n - 1];

    for(int i = m - 1; i >= 0; i--) {
        for(int j = n - 1; j >= 0; j--) {
            if(i == m - 1 && j == n - 1) continue;
            int down, right;
            if(i < m - 1 && j < n - 1) {
                down = dp[i + 1][j];
                right = dp[i][j + 1];
            }
            else if(i >= m - 1 && j < n - 1) {
                down = INT_MAX;
                right = dp[i][j + 1];
            }
            else if(i < m - 1 && j >= n - 1) {
                down = dp[i + 1][j];
                right = INT_MAX;
            }
            dp[i][j] = grid[i][j] + min(down, right);
        }
    }

    return dp[0][0];
}


// Space Optmization
// TC → O(m * n)
// TC → O(n)
int minSumPath3(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(2, vector<int>(n, 0));
    dp[0][n - 1] = grid[m - 1][n - 1];

    for(int i = m - 1; i >= 0; i--) {
        for(int j = n - 1; j >= 0; j--) {
            if(i == m - 1 && j == n - 1) continue;
            int down, right;
            if(i < m - 1 && j < n - 1) {
                down = dp[1][j];
                right = dp[0][j + 1];
            }
            else if(i >= m - 1 && j < n - 1) {
                down = INT_MAX;
                right = dp[0][j + 1];
            }
            else if(i < m - 1 && j >= n - 1) {
                down = dp[1][j];
                right = INT_MAX;
            }
            dp[0][j] = grid[i][j] + min(down, right);
        }
        for(int i = 0; i < n; i++) {
            dp[1][i] = dp[0][i];
            dp[0][i] = 0;
        }
    }

    return dp[1][0];
}

int main() {
    vector<vector<int>> grid = {
        {5, 9, 6},
        {11, 5, 2}
    };
    cout << minSumPath1(grid) << endl;
    cout << minSumPath2(grid) << endl;
    cout << minSumPath3(grid) << endl;
    return 0;
}