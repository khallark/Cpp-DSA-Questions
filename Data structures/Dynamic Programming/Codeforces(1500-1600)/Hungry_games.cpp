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

int t, n;

int main() {
    cin >> t;
    while(t--) {
        ll x;
        cin >> n >> x;
        vector<ll> a(n + 1);
        for(int i = 1; i <= n; i++) cin >> a[i];
        vector<ll> pf(n + 1);
        for(int i = 1; i <= n; i++) {
            pf[i] = a[i] + pf[i - 1];
        }
        vector<ll> dp(n + 2);
        for(int l = n - 1; l >= 0; l--) {
            int r = upper_bound(pf.begin(), pf.end(), x + pf[l]) - pf.begin();
            // cout << '[' << r << ']' << endl;
            dp[l] = dp[r] + r - (l + 1);
        }
        ll count = 0;
        for(auto i : dp) count += i;
        cout << count << endl << endl;
    }
    return 0;
}