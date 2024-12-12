#include <iostream>
#include <vector>
using namespace std;
const int M=1000000007;
int solve(vector<vector<int>> &dp, int n, int num) {
    if(num == n) return 1;
    if(num > n) return 0;
    int ways = 0;
    for(int i = 1; i <= 6; i++) {
        if(dp[i - 1][n - num - 1] != -1) ways = (0LL+ ways + dp[i - 1][n - num - 1])%M;
        else ways =( 0LL+ ways + solve(dp, n - num, i))%M;
    }
    return dp[num - 1][n - 1] = ways;
}
int NumCombos(int n) {
    int ans = 0;
    vector<vector<int>> dp(6, vector<int>(n, -1));
    for(int i = 1; i <= 6; i++) {
        ans = (ans+ 0LL+solve(dp, n, i))%M;
    }
    return ans;
}
int main() {
    int n = 7;
    cin>>n;
    cout << NumCombos(n) << endl;
    return 0;
}