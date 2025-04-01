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

int t, n, m, k;

bool ps(int mid) {
    int numDesks = k;
    int l = mid;
    for(int i = 0; i < n && numDesks; i++) {
        l = mid;
        for(int j = 0; j < m && numDesks; j++) {
            l--;
            numDesks--;
            if(!l) l = mid, j++;
        }
    }
    return !numDesks;
}

int main() {
    cin >> t;
    vector<int> anss(t);
    while(t--) {
        cin >> n >> m >> k;
        int l = 1, r = min(k, m);
        int mid = l + (r - l) / 2;
        int ans = -1;
        while(l <= r) {
            if(ps(mid)) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
            mid = l + (r - l) / 2;
        }
        anss[t] = ans;
    }
    cout << endl;
    for(auto i : anss) cout << i << endl;
    return 0;
}