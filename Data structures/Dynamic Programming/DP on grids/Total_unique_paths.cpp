#include <iostream>
#include <vector>
using namespace std;

// Recursion with DP (Memoization)
// TC → O(m * n)
// TC → O(m * n)
int solve(vector<vector<int>> &dp , int &m, int &n, int p1, int p2) {
    if(p1 >= m || p2 >= n) {
        return 0;
    }
    if(p1 == m - 1 && p2 == n - 1) {
        return 1;
    }
    if(dp[p1][p2] > 0) {
        return dp[p1][p2];
    }

    int down = solve(dp, m, n, p1 + 1, p2);
    int right = solve(dp, m, n, p1, p2 + 1);

    return dp[p1][p2] = down + right;
}
int uniquePaths1(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));
    return solve(dp, m, n, 0, 0);
}


// Iteration with DP (Tabulation)
// TC → O(m * n)
// TC → O(m * n)
int uniquePaths2(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[m - 1][n - 1] = 1;

    for(int i = m - 1; i >= 0; i--) {
        for(int j = n - 1; j >= 0; j--) {
            if(i == m - 1 && j == n - 1) continue;
            int down, right;
            if(i < m - 1 && j < n - 1) {
                down = dp[i + 1][j];
                right = dp[i][j + 1];
            }
            else if(i >= m - 1 && j < n - 1) {
                down = 0;
                right = dp[i][j + 1];
            }
            else if(i < m - 1 && j >= n - 1) {
                down = dp[i + 1][j];
                right = 0;
            }
            dp[i][j] = down + right;
        }
    }

    return dp[0][0];
}


// Space Optmization
// TC → O(m * n)
// TC → O(n)
int uniquePaths3(int m, int n) {
    vector<vector<int>> dp(2, vector<int>(n, 0));
    dp[0][n - 1] = 1;

    for(int i = m - 1; i >= 0; i--) {
        for(int j = n - 1; j >= 0; j--) {
            if(i == m - 1 && j == n - 1) continue;
            int down, right;
            if(i < m - 1 && j < n - 1) {
                down = dp[1][j];
                right = dp[0][j + 1];
            }
            else if(i >= m - 1 && j < n - 1) {
                down = 0;
                right = dp[0][j + 1];
            }
            else if(i < m - 1 && j >= n - 1) {
                down = dp[1][j];
                right = 0;
            }
            dp[0][j] = down + right;
        }
        for(int i = 0; i < n; i++) {
            dp[1][i] = dp[0][i];
            dp[0][i] = 0;
        }
    }

    return dp[1][0];
}


int main() {
    int m = 7, n = 5;
    cout << uniquePaths1(m, n) << endl;
    cout << uniquePaths2(m, n) << endl;
    cout << uniquePaths3(m, n) << endl;
    return 0;
}