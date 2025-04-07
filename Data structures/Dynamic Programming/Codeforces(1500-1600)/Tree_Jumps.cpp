#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int, int>
#define pll pair<ll, ll>
#define REP(i, x, y) for(int i = x; i < y; i++)
#define REPR(i, x, y) for(int i = x; i >= y; i--)
using namespace std;

int t, n;
const int MOD = 998244353;

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> parent(n + 1);
        vector<vector<int>> tree(n + 1);
        for(int i = 2; i <= n; i++) {
            int p;
            cin >> p;
            parent[i] = p;
            tree[p].push_back(i);
        }
        vector<vector<int>> level(n);
        queue<pi> q;
        q.push({1, 0});
        int maxDepth = 0;
        while(!q.empty()) {
            auto [node, lvl] = q.front();
            maxDepth = max(maxDepth, lvl);
            q.pop();
            level[lvl].push_back(node);
            for(auto child : tree[node]) {
                q.push({child, lvl + 1});
            }
        }
        vector<int> dp(n + 1, 1);
        vector<int> sum(n);
        sum[maxDepth] = level[maxDepth].size();
        for(int lvl = maxDepth - 1; lvl >= 1; lvl--) {
            int dpSum = 0;
            for(auto node : level[lvl]) {
                int s = 0;
                for(auto child : tree[node]) {
                    s = (0LL + s + dp[child]) % MOD;
                }
                dp[node] = (0LL + dp[node] + sum[lvl + 1]- s + MOD) % MOD;
                dpSum = (0LL + dpSum + dp[node]) % MOD;
            }
            sum[lvl] = dpSum;
        }
        cout << (0LL + sum[1] + 1) % MOD << endl;
    }
    return 0;
}