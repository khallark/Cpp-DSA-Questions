#include <iostream>
#include <vector>
#include <matrix.h>
using namespace std;
int numTrees(int n) {
    vector<vector<int>> dp(n + 2, vector<int>(n + 2));

    for(int i = 0; i <= n; i++) {
        dp[i][i + 1] = 1;
    }

    for(int i = n; i >= 0; i--) {
        for(int j = i + 2; j <= n + 1; j++) {
            int sum = 0;
            for(int k = i + 1; k < j; k++) {
                sum += dp[i][k] * dp[k][j];
            }
            dp[i][j] = sum;
        }
    }
    
    return dp[0][n + 1];
}
int main() {
    cout << numTrees(4) << endl;
    return 0;
}