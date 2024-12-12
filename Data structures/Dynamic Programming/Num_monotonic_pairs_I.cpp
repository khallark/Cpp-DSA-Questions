#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int M = 1000000007;

int countOfPairs(vector<int>& nums) {
    int max_ele = *max_element(nums.begin(), nums.end());
    vector<vector<int>> dp(2, vector<int>(max_ele + 1));

    for(int i = 0; i <= max_ele; i++) dp[1][i] = 1;

    for(int i = nums.size() - 2; i >= 0; i--) {
        for(int j = 0; j <= max_ele; j++) {
            int count = 0;
            for(int k = j; k <= nums[i + 1]; k++) {
                if(nums[i] - j < nums[i + 1] - k) continue;
                count = (count + dp[1][k]) % M;
            }
            dp[0][j] = count;
        }
        dp[1] = dp[0];
        dp[0] = vector<int>(max_ele + 1);
    }

    int ans = 0;
    for(int i = 0; i <= max_ele; i++) ans = (ans + dp[1][i]) % M;
    return ans;
}

int main() {
    vector<int> nums = {2, 3, 2};
    cout << countOfPairs(nums) << endl;
    return 0;
}