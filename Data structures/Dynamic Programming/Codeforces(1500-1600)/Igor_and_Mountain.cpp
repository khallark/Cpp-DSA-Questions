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

vector<vector<vector<int>>> dp;
vector<vector<char>> grid;
int n, m;
double d;

// codeforces Codeforces Round 1013 (Div. 3) F. Igor and Mountain

double ed(int i1, int j1, int i2, int j2) {
    return sqrt(((i1 - i2) * (i1 - i2)) + ((j1 - j2) * (j1 - j2)));
}

int solve(int i, int j, int k) {
    if(dp[i][j][k] != -1) return dp[i][j][k];

    dp[i][j][k] = 0;

    if(grid[i][j] == '#') return dp[i][j][k];

    if(i == 0) {
        dp[i][j][k] = 1;
        if(k == 1) return dp[i][j][k];
    }

    int I, J;
    if(!k) {
        J = j + 1;
        while(J < m && d >= ed(i, j, i, J)) {
            dp[i][j][k] += solve(i, J, 1);
            J++;
        }
        J = j - 1;
        while(J >= 0 && d >= ed(i, j, i, J)) {
            dp[i][j][k] += solve(i, J, 1);
            J--;
        }
    }
    I = i - 1;
    J = j;
    while(I >= 0 && J < m && d >= ed(i, j, I, J)) {
        dp[i][j][k] += solve(I, J, 0);
        J++;
    }
    J = j - 1;
    while(I >= 0 && J >= 0 && d >= ed(i, j, I, J)) {
        dp[i][j][k] += solve(I, J, 0);
        J--;
    }
    return dp[i][j][k];
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m >> d;
        grid.assign(n, vector<char>(m));
        dp.assign(n, vector<vector<int>>(m, vector<int>(2, 0)));
        for(auto& i : grid) {
            for(auto& j : i) {
                cin >> j;
            }
        }
        for(int j = 0; j < m; j++) {
            if(grid[0][j] != '#') dp[0][j][0] = dp[0][j][1] = 1;
        }
        int I, J;
        for(int i = 0; i < n; i++) {
            for(int k = 1; k >= 0; k--) {
                for(int j = 0; j < m; j++) {
                    if(grid[i][j] == '#') continue;
                    if(!k) {
                        J = j + 1;
                        while(J < m && d >= ed(i, j, i, J)) dp[i][j][k] = (0LL + dp[i][j][k] + dp[i][J++][1]) % 998244353;
                        J = j - 1;
                        while(J >= 0 && d >= ed(i, j, i, J)) dp[i][j][k] = (0LL + dp[i][j][k] + dp[i][J--][1]) % 998244353;
                    }
                    I = i - 1, J = j;
                    while(I >= 0 && J < m && d >= ed(i, j, I, J)) dp[i][j][k] = (0LL + dp[i][j][k] + dp[I][J++][0]) % 998244353;
                    J = j - 1;
                    while(I >= 0 && J >= 0 && d >= ed(i, j, I, J)) dp[i][j][k] = (0LL + dp[i][j][k] + dp[I][J--][0]) % 998244353;
                }
            }
        }
        int ans = 0;
        for(int j = 0; j < m; j++) ans = (0LL + ans + dp[n - 1][j][0]) % 998244353;
        cout << ans << endl;
    }
    return 0;
}