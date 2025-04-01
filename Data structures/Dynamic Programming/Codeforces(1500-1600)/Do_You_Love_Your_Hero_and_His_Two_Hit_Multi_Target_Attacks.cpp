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

int main() {
    int t, k;
    cin >> t;
    vi dp(501);
    for(int i = 2; i <= 500; i++) {
        dp[i] = (i * (i - 1)) / 2;
    }
    for(int a = 0; a < t; a++) {
        cin >> k;
        vi arr;
        while(k) {
            auto it = lower_bound(dp.begin(), dp.end(), k); // smallest combination >= 'k'
            if(it != dp.end() && *it == k) {
                arr.push_back(it - dp.begin());
                k = 0;
            } else {
                if(it == dp.begin()) break;
                --it;
                arr.push_back(it - dp.begin());
                k -= *(it);
            }
        }
        vector<pair<int, int>> ans;
        int x = 1;
        int y = 1;
        for(auto n : arr) {
            REP(i, 0, n) ans.push_back({x, y++});
            x++;
        }
        cout << ans.size() << endl;
        for(auto i : ans) {
            cout << i.first << " " << i.second << endl;
        }
    }
    return 0;
}