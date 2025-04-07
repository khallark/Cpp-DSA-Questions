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

int t, n, m, v;

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> m >> v;
        vector<ll> cake(n);
        for(auto& i : cake) cin >> i;
        ll sum = 0;
        for(auto i : cake) sum += i;
        if(sum < v) {
            cout << -1 << endl;
            continue;
        }
        vector<ll> prefixSum(n + 1);
        prefixSum[0] = 0;
        for(int i = 1; i <= n; i++) prefixSum[i] = prefixSum[i - 1] + cake[i - 1];
        vector<int> prefDP(m + 1);
        prefDP[0] = -1;
        sum = 0;
        int i = 0;
        while(i < n && sum < v) {
            sum += cake[i];
            i++;
        }
        prefDP[1] = i - 1;
        int j = 2;
        while(j <= m) {
            i = prefDP[j - 1] + 1;
            sum = 0;
            while(i < n && sum < v) {
                sum += cake[i];
                i++;
            }
            if(i >= n) {
                if(sum >= v) prefDP[j] = i - 1;
                else prefDP[j] = n;
            } else {
                prefDP[j] = i - 1;
            }
            j++;
        }
        vector<int> suffDP(m + 1);
        suffDP[0] = n;
        sum = 0;
        i = n - 1;
        while(i >= 0 && sum < v) {
            sum += cake[i];
            i--;
        }
        suffDP[1] = i + 1;
        j = 2;
        while(j <= m) {
            i = suffDP[j - 1] - 1;
            sum = 0;
            while(i >= 0 && sum < v) {
                sum += cake[i];
                i--;
            }
            if(i < 0) {
                if(sum >= v) suffDP[j] = i + 1;
                else suffDP[j] = -1;
            } else {
                suffDP[j] = i + 1;
            }
            j++;
        }
        int x = 0, y = m;
        ll ans = -1;
        while(x <= m) {
            int l = prefDP[x] + 1;
            int r = suffDP[y] - 1;
            if(l <= r) ans = max(ans, prefixSum[r + 1] - prefixSum[l]);
            else if (l - r == 1) ans = max(ans, 0LL);
            x++, y--;
        }
        cout << ans << endl << endl;
    }
    return 0;
}