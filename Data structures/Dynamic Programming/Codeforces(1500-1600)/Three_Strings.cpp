#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int, int>
#define pll pair<ll, ll>
#define REP(i, x, y) for(int i = x; i < y; i++)
#define REPR(i, x, y) for(int i = x; i >= y; i--)
using namespace std;

int t;
string a, b, c;

int main() {
    cin >> t;
    while(t--) {
        cin >> a >> b >> c;
        int n = a.length(), m = b.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for(int i = 1; i <= n; i++) {
            dp[i][0] = dp[i - 1][0] + (a[i - 1] != c[i - 1]);
        }
        for(int i = 1; i <= m; i++) {
            dp[0][i] = dp[0][i - 1] + (b[i - 1] != c[i - 1]);
        }
        for(int a_index = 1; a_index <= n; a_index++) {
            for(int b_index = 1; b_index <= m; b_index++) {
                dp[a_index][b_index] = min(
                    dp[a_index - 1][b_index] + (a[a_index - 1] != c[a_index + b_index - 1]),
                    dp[a_index][b_index - 1] + (b[b_index - 1] != c[a_index + b_index - 1])
                );
            }
        }
        cout << dp[n][m] << endl;
    }
    return 0;
}