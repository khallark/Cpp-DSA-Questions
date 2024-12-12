#include <iostream>
#include <climits>
#include <vector>
using namespace std;





// Simple Recursion
int solve(vector<int> &arr, vector<vector<int>> &dp, int i, int j) {
    if(i == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int mini = INT_MAX;
    for(int k = i; k < j; k++) {
        int steps = (arr[i - 1] * arr[k] * arr[j]) + (solve(arr, dp, i, k) + solve(arr, dp, k + 1, j));
        mini = min(mini, steps);
    }

    return dp[i][j] = mini;
}
int matrixMultiplication1(vector<int> &arr, int N) {
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return solve(arr, dp, 1, N - 1);
}





// Tabulation
int matrixMultiplication2(vector<int> &arr, int N) {
    vector<vector<int>> dp(N, vector<int>(N));
    
    for(int i = N - 1; i > 0; i--) {
        for(int j = i + 1; j <= N - 1; j++) {
            int mini = INT_MAX;
            for(int k = i; k < j; k++) {
                int steps = (arr[i - 1] * arr[k] * arr[j]) + (dp[i][k] + dp[k + 1][j]);
                mini = min(mini, steps);
            }

            dp[i][j] = mini;
        }
    }

    return dp[1][N - 1];
}





int main() {
    vector<int> dims = {10, 15, 20, 25};
    cout << matrixMultiplication2(dims, dims.size());
    return 0;
}