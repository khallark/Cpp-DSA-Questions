#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dp;
int f(int l, int r) {
    if(l > r) return dp[l][r] = 1;
    // if(dp[l][r] != -1) return dp[l][r];
    int ans = 0;
    for(int m = l; m <= r; m++) {
        ans += f(l, m - 1) * f(m + 1, r);
    }
    return dp[l][r] = ans;
}
int numTrees(int n) {
    dp.resize(n + 2, vector<int>(n + 2, -1));
    return f(1, n);
}
int main() {
    cout << numTrees(8) << endl;
    return 0;
}