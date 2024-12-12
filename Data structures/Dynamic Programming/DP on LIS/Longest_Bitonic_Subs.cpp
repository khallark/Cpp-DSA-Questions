#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int longestBitonicSubsequence(int arr[], int n)
{
    vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>>(n + 1, {0, 0}));

    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j <= n; j++) {

            int len = dp[i + 1][j].first;
            if(j == 0 || arr[i] > arr[j - 1])
                len = max(len, dp[i + 1][i + 1].first + 1);
            else if(arr[i] < arr[j - 1])
                len = max(len, dp[i + 1][i + 1].second + 1);
            dp[i][j].first = len;


            len = dp[i + 1][j].second;
            if(j == 0 || arr[i] < arr[j - 1])
                len = max(len, dp[i + 1][i + 1].second + 1);
            dp[i][j].second = len;

        }
    }

    return max(dp[0][0].first, dp[0][0].second);
}
int main() {
    int arr[] = {1, 2, 3, 3, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << longestBitonicSubsequence(arr, size);
    return 0;
}