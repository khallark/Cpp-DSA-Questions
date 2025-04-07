#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

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
const int mod = 998244353;
void solve() {
    cin >> n;
    vector<int> a(n);
    for(auto& i : a) cin >> i;
    if(n == 1) {
        cout << 1 + (a[0] == 0) << endl;
        return;
    }
    map<vi, ll> old_dp;
    old_dp[{0,0}] = (a[0] == 0);
    old_dp[{1,1}] = 1;
    for(int i = 1; i < n; i++) {
        map<vi, ll> new_dp;
        new_dp[{a[i],0}] = (0LL + old_dp[{a[i],0}] + old_dp[{a[i],1}]) % mod;
        new_dp[{a[i - 1] + 1, 1}] = old_dp[{a[i - 1],0}];
        old_dp = new_dp;
    }
    cout << (0LL + old_dp[{a[n - 1],0}] + old_dp[{a[n - 2] + 1, 1}]) % mod << endl;
}

int main() {
    cin >> t;
    while(t--) solve();
    return 0;
}