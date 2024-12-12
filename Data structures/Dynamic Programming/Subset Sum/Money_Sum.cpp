#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto& i : arr) cin >> i;


    int k = 0;
    for(auto i : arr) k += i;
    vector<vector<bool>> dp(n, vector<bool>(k + 1));
    for(int i = 0; i < n; i++) dp[i][0] = 1;
    dp[0][arr[0]] = 1;
    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= k; j++) {
            bool notPick = dp[i - 1][j];
            bool pick = 0;
            if(j - arr[i] >= 0) {
                pick = dp[i - 1][j - arr[i]];
            }
            dp[i][j] = pick || notPick;
        }
    }
    vector<int> ans;
    for(int i = 1; i <= k; i++) {
        if(dp[n - 1][i]) ans.push_back(i);
    }


    cout << ans.size() << endl;
    for(auto i : ans) cout << i << " ";
    return 0;
}