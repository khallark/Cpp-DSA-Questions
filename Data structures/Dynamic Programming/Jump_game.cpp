#include <iostream>
#include <vector>
using namespace std;

// DP Solution [O(n²)]
bool canJump(vector<int>& nums) {
    int n = nums.size();
    vector<bool> dp(n);
    dp[n - 1] = true;
    for(int i = n - 2; i >= 0; i--) {
        bool can = false;
        for(int j = i + 1; !can && j < n && j <= i + nums[i]; j++) {
            can = can | dp[j];
        }
        dp[i] = can;
    }

    return dp[0];
}


// Greedy Solution [O(n)]
bool canJump(vector<int>& nums) {
    int n = nums.size();
    int maxReach = 0;
    for(int i = 0; i < n; i++) {
        if(i > maxReach) return false;
        maxReach = max(maxReach, i + nums[i]);
    }
    return true;
}

int main() {
    vector<int> jumps = {2, 3, 1, 1, 4};
    cout << canJump(jumps) << endl;
    return 0;
}