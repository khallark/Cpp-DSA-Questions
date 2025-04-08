#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

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
        cin >> n;
        vector<ll> v(n + 1);
        for(int i = 1; i <= n; i++) cin >> v[i];
        vector<pll> a;
        for(int i = 2; i <= n; i++) {
            a.push_back({v[i] + i - 1, i - 1});
        }
        sort(a.begin(), a.end());
        set<ll> s;
        s.insert(n);
        for(int i = 0; i < n - 1; i++) {
            if(s.find(a[i].first) != s.end()) {
                s.insert(a[i].first + a[i].second);
            }
        }
        cout << *s.rbegin() << endl;
    }
    return 0;
}