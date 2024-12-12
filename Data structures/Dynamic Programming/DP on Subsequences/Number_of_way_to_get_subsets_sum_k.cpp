#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &arr, vector<vector<int>> &dp, int n, int k) {
	if(k == 0) return 1;
	if(n == 0) return arr[n] == k;
	if(dp[n][k] != -1) return dp[n][k];

	int notTake = solve(arr, dp, n - 1, k);
	int take = 0;
	if(arr[n] <= k) {
		take = solve(arr, dp, n - 1, k - arr[n]);
	}
	return dp[n][k] = take + notTake;
}

int findWays1(vector<int>& arr, int k) {
	vector<vector<int>> dp(arr.size(), vector<int>(k + 1, -1));
	return solve(arr, dp, arr.size() - 1, k);
}

int findWays2(vector<int>& arr, int k_) {
	vector<vector<int>> dp(arr.size(), vector<int>(k_ + 1));

	// Base Case 1:
	for(int i = 0; i < arr.size(); i++) {
		dp[i][0] = 1;
	}

	// Base Case 2:
	if(arr[0] <= k_) dp[0][arr[0]] = 1;
	for(int n = 1; n < arr.size(); n++) {
		for(int k = 1; k <= k_; k++) {
			int notTake = dp[n - 1][k];
			int take = 0;
			if(arr[n] <= k) {
				take = dp[n - 1][k - arr[n]];
			}
			dp[n][k] = take + notTake;
		}
	}
	for(auto i : dp) {
		for(auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	return dp[arr.size() - 1][k_];
}

int main() {
	vector<int> arr = {3, 1, 3, 4};
    int k = 7;
    findWays2(arr, k);
	return 0;
}