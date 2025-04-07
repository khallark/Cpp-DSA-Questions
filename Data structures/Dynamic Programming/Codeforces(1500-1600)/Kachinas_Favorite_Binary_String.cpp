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

int query(int l, int r) {
    cout << "? " << l << " " << r << flush;
    int ans;
    cin >> ans;
    return ans;
}

void solve(int n) {
    string ans = "";

    
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        solve(n);
    }
    return 0;
}