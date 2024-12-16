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

int query(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int ans;
    cin >> ans;
    return ans;
}

void solve() {
    int n;
    cin >> n;
    string s(n, '0');
    vector<int> Q(n);
    int I = n - 2;
    Q[I] = query(I + 1, n);
    while(I >= 0 && Q[I] == 0) {
        I--;
        Q[I] = query(I + 1, n);
    }
    if(I < 0) cout << "! IMPOSSIBLE" << endl;
    
    for(int i = I + 1; i < I + 1 + Q[I]; i++) {
        s[i] = '1';
    }
    for(int i = I - 1; i >= 0; i--) {
        Q[i] = query(i + 1, n);
        s[i] = Q[i] > Q[i + 1] ? '0' : '1';
    }
    cout << "! " << s << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}