#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
vector<int> longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> dp(n);
    dp[0] = 1;
    for(int i = 1; i < n; i++) {
        int maxi = INT_MIN;
        
        for(int j = 0; j < i; j++)
            if(arr[j] < arr[i])
                maxi = max(maxi, dp[j] + 1);

        dp[i] = maxi == INT_MIN ? 1 : maxi;
    }
    int ans = INT_MIN, ind;
    for(int i = 0; i < n; i++) if(ans < dp[i]) ind = i, ans = dp[i];
    vector<int> ar(ans);
    ar[ans-- - 1] = arr[ind];

    for(int i = ind - 1; i >= 0 && ans >= 1; i--)
        if(dp[i] == ans)
            ar[ans-- - 1] = arr[i];

    return ar;
}
int main() {
    int arr[] = {1, 7, 8, 4, 5, 6, -1, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    for(auto i : longestIncreasingSubsequence(arr, size)) {
        cout << i << " ";
    }
    return 0;
}