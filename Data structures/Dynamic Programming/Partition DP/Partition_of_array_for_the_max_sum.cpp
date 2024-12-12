#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int maximumSubarray(vector<int> &arr, int k) {
    int n = arr.size();
    vector<int> dp(n + 1);

    for(int i = n - 1; i >= 0; i--) {
        int maxi = INT_MIN;
        int sum =  INT_MIN;
        for(int j = i; j < n && j < i + k; j++) {
            maxi = max(maxi, arr[j]);
            sum = max(sum, (maxi * (j - i + 1)) + dp[j + 1]);
        }
        dp[i] = sum;
    }

    return dp[0];
}
int main() {
    vector<int> arr = {1, 21, 1, 5, 4};
    int k = 2;
    cout << maximumSubarray(arr, k) << endl;
    return 0;
}