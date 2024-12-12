#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int rectangle_cutting(int a, int b) {
    if(a == b) return 0;
    vector<vector<int>> dp(a + 1, vector<int>(b + 1));
    for(int i = 1; i <= min(a, b); i++) dp[i][i] = 0;
    
    for(int i = 1; i <= a; i++) {
        for(int j = 1; j <= b; j++) {
            if(i == j) continue;

            int ans = INT_MAX;

            for(int k = 1; k < j; k++)
                ans = min(ans, dp[i][k] + dp[i][j - k]);
            for(int k = 1; k < i; k++)
                ans = min(ans, dp[k][j] + dp[i - k][j]);
                
            dp[i][j] = ans + 1;
        }
    }

    return dp[a][b];
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << rectangle_cutting(a, b) << endl;
    return 0;
}