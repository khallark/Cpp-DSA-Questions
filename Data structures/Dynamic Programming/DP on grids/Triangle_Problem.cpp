#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Recursion with DP (Memoization)
// TC → O(m * n)
// TC → O(m * n)
int solve(vector<vector<int>> &triangle, vector<vector<int>> &dp, int n, int i, int j) {
    if(i == n - 1) {
        return triangle[i][j];
    }
    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    int down = solve(triangle, dp, n, i + 1, j);
    int diagonal = solve(triangle, dp, n, i + 1, j + 1);
    
    return dp[i][j] = triangle[i][j] + min(down, diagonal);
}
int minimumPathSum1(vector<vector<int>>& triangle, int n) {
	vector<vector<int>> dp;
    for(auto i : triangle) {
        dp.push_back(vector<int>(i.size(), -1));
    }
    return solve(triangle, dp, n, 0, 0);
}


// Iteration with DP (Tabulation)
// TC → O(m * n)
// TC → O(m * n)
int minimumPathSum2(vector<vector<int>>& triangle, int n) {
    vector<vector<int>> dp;
    for(auto i : triangle) {
        dp.push_back(vector<int>(i.size()));
    }
    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j <= i; j++) {
            if(i == n - 1) {
                dp[i][j] = triangle[i][j];
            }
            else {
                int down = dp[i + 1][j];
                int diagonal = dp[i + 1][j + 1];
                dp[i][j] = triangle[i][j] + min(down, diagonal);
            }
        }
    }

    return dp[0][0];
}


// Space Optmization
// TC → O(m * n)
// TC → O(n)
int minimumPathSum3(vector<vector<int>>& triangle, int n) {
    vector<int> dp(n);
    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j <= i; j++) {
            if(i == n - 1) {
                dp[j] = triangle[i][j];
            }
            else {
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
        }
    }

    return dp[0];
}

int main() {
    vector<vector<int>> triangle = {
        {1},
        {2, 3},
        {3, 6, 7},
        {8, 9, 6, 10}
    };

    int n = triangle.size();
    cout << minimumPathSum1(triangle, n) << endl;
    cout << minimumPathSum2(triangle, n) << endl;
    cout << minimumPathSum3(triangle, n);

    return 0;
}