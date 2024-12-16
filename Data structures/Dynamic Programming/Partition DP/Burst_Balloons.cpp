#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dp;
vector<int> a;
int n;
int f(int i, int j) {
    if (i > j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int coins = 0;
    for(int k = i; k <= j; k++) {
        coins = max(coins, f(i, k - 1) + (a[i - 1] * a[k] * a[j + 1]) + f(k + 1, j));
    }
    return dp[i][j] = coins;
}
int maxCoins(vector<int> nums) {
    n = nums.size();
    a.resize(n + 2);
    for(int i = 1; i <= n; i++) a[i] = nums[i - 1];
    a[0] = a[n + 1] = 1;
    dp.resize(n + 2, vector<int>(n + 2, -1));
    return f(1, n);
}

int main() {
    cout << maxCoins(vector<int>({3, 1, 5, 8}));
    return 0;
}
