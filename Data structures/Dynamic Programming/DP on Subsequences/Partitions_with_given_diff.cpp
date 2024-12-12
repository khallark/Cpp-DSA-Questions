#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int MOD = 10e9 + 7;

int findWays(vector<int>& arr, int k_) {
	vector<vector<int>> dp(arr.size(), vector<int>(k_ + 1));
	for(int i = 0; i < arr.size(); i++) dp[i][0] = 1;
	if(arr[0] <= k_) dp[0][arr[0]] = 1;

	for(int n = 1; n < arr.size(); n++) {
		for(int k = 1; k <= k_; k++) {
			int notTake = dp[n - 1][k];
			int take = 0;
			if(arr[n] <= k) take = dp[n - 1][k - arr[n]];
			dp[n][k] = (take + notTake) % MOD;
		}
	}
	return dp[arr.size() - 1][k_];
}


int countPartitions(int n, int d, vector<int> &arr) {
    int sum = 0;
    for(auto i : arr) {
        sum += i;
    }
    if((sum + d)&1) return 0;
    int s1 = (sum + d) / 2;
    return findWays(arr, s1);
}

int main() {
    vector<int> arr = {24, 36, 1, 3, 29, 0, 38, 17, 35, 31, 42, 30, 44, 35, 22};
    int size = arr.size();
    cout << countPartitions(size, 21, arr);
    return 0;
}