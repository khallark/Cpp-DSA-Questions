#include <iostream>
#include <vector>
using namespace std;
int findWays(vector<int>& arr, int k_) {
	vector<vector<int>> dp(arr.size(), vector<int>(k_ + 1));
	for(int i = 0; i < arr.size(); i++) dp[i][0] = 1;
	if(arr[0] <= k_) dp[0][arr[0]] = 1;

	for(int n = 1; n < arr.size(); n++) {
		for(int k = 1; k <= k_; k++) {
			int notTake = dp[n - 1][k];
			int take = 0;
			if(arr[n] <= k) take = dp[n - 1][k - arr[n]];
			dp[n][k] = (take + notTake);
		}
	}
	return dp[arr.size() - 1][k_];
}

int targetSum(int n, int target, vector<int>& arr) {
    int sum = 0;
    for(auto i : arr) {
        sum += i;
    }
    if((sum + target)&1) return 0;
    int s1 = (sum + target) / 2;
    return findWays(arr, s1);
}
int main() {
    vector<int> arr = {1, 1, 1, 1, 1};
    cout << targetSum(arr.size(), 5, arr);
    return 0;
}