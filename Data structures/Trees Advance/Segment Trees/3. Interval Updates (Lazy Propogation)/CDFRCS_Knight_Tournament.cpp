#include <iostream>
#include <set>
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
    int n, m;
    cin >> n >> m;
    set<int> alive;
    REP(i, 1, n + 1) alive.insert(i);
    vector<int> ans(n + 1, 0);
    REP(i, 0, m) {
        int l, r, w;
        cin >> l >> r >> w;
        auto it = alive.lower_bound(l);
        while(*it <= r && it != alive.end()) {
            if(*it != w) {
                ans[*it] = w;
                auto kill = it;
                it++;
                alive.erase(kill);
            }
            else it++;
        }
    }
    REP(i, 1, 9) cout << ans[i] << " ";
    cout << endl;
    return 0;
}