#include <iostream>
#include <vector>
#include <map>
using namespace std;

int numberOfArithmeticSlices(vector<int> nums) {
    int n = nums.size();
    int ans = 0;
    if(n < 3) return 0;
    vector<map<int, int>> dp(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            long diff = (long)nums[i] - (long)nums[j];
            if(diff < INT_MIN or diff > INT_MAX) continue;
            int count = dp[j][diff];
            dp[i][diff] += 1 + count;
            ans += count;
        }
    }
    return ans;
}

int main() {
    cout << numberOfArithmeticSlices(vector<int>({1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 2, 1, 2, 1}));
    return 0;
}