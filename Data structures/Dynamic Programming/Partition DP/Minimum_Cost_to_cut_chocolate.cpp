#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Simple Recursion
int f(vector<int> &cuts, int i, int j) {
    int mini = INT_MAX;
    for(auto k : cuts) {
        if(k > i && k < j) {
            int totalCost = (j - i) + (f(cuts, i, k) + f(cuts, k, j));
            mini = min(mini, totalCost);
        }
    }
    return mini == INT_MAX ? 0 : mini;
}
int cost1(int n, int c, vector<int> &cuts) {
    return f(cuts, 0, n);
}



int cost2(int n, int c, vector<int> &cuts) {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    
    int maxCut = INT_MIN;
    for(auto i : cuts) {
        maxCut = max(maxCut, i);
    }

    for(int i = maxCut; i >= 0; i--) {
        for(int j = i + 1; j <= n; j++) {
            int mini = INT_MAX;
            for(auto k : cuts) {
                if(k > i && k < j) {
                    int totalCost = (j - i) + (dp[i][k] + dp[k][j]);
                    mini = min(mini, totalCost);
                }
            }
            dp[i][j] = mini == INT_MAX ? 0 : mini;
        }
    }

    return dp[0][n];
}



int main() {
    vector<int> cuts = {1, 3, 4};
    int n = 5;
    int c = cuts.size();
    cout << cost2(n, c, cuts) << endl;
    return 0;
}