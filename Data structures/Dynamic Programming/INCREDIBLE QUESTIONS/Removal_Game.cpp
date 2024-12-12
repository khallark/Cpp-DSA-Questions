#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<vector<long long>> dp(5005, vector<long long>(5005));
    int n;
    cin >> n;
    vector<long long> nums(n);
    for(auto& i : nums) {
        cin >> i;
    }
    for(int i = 0; i < n; i++) dp[i][i] = nums[i];
    for(int i = 0; i < n - 1; i++) dp[i][i + 1] = max(nums[i], nums[i + 1]);
    for(int i = n - 3; i >= 0; i--) {
        for(int j = i + 2; j < n; j++) {
            dp[i][j] = max(
                nums[i] + min(dp[i + 2][j], dp[i + 1][j - 1]),
                nums[j] + min(dp[i + 1][j - 1], dp[i][j - 2])
            );
        }
    }
    cout << dp[0][n - 1] << endl;
    return 0;
}