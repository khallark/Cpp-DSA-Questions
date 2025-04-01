#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>

#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int, int>
#define pll pair<ll, ll>
#define REP(i, x, y) for(int i = x; i < y; i++)
#define REPR(i, x, y) for(int i = x; i >= y; i--)
#define mp(a, b) make_pair(a, b)
using namespace std;

ll t, n, k;
unordered_map<int, pair<ll, ll>> dp;

// ll solve(ll l, ll r) {
//     ll m = l + (r - l) / 2;
//     if(r - l + 1 < k) return 0;
//     if((r - l + 1) & 1) {
//         return m + solve(l, m - 1) + solve(m + 1, r);
//     }
//     else {
//         return solve(l, m) + solve(m + 1, r);
//     }
// }

pair<ll, ll> solve(ll l, ll r) {
    ll L = r - l + 1;

    if(L < k) return mp(0, 0);

    if(dp.find(L) != dp.end()) {
        return mp(dp[L].first + (l - 1) * dp[L].second, dp[L].second);
    }

    if(L & 1) {
        if(L != 1) {
            auto a = solve(l, l + L/2 - 1);
            auto b = solve(l + L/2 + 1, r);
            pair<ll, ll> lr = mp(a.first + b.second + l + L/2, a.second + b.second + 1);
            dp[L] = mp(lr.first - lr.second * (l - 1), lr.second);
            return lr;
        } else {
            dp[1] = mp(1, 1);
            return mp(l, 1);
        }
    } else {
        auto a = solve(l, l + L/2 - 1);
        auto b = solve(l + L/2, r);
        pair<ll, ll> lr = mp(a.first + b.first, a.second + b.second);
        dp[L] = mp(lr.first - lr.second * (l - 1), lr.second);
        return lr;
    }
}

int main() {
    k = 1;
    dp.clear();
    cout << endl << solve(1, 8765432).first;
    return 0;
}