#include <iostream>
#include <vector>
#define ll long long
using namespace std;
int t;
ll y, x;
ll f() {
    ll layer = max(y, x);
    ll ans;
    if(layer & 1) {
        ll mini = (layer - 1) * (layer - 1) + 1;
        if(y >= x) {
            ans = (mini + x - 1);
        }
        else {
            ans = (mini + x - 1) + (x - y);
        }
    } else {
        ll mini = (layer - 1) * (layer - 1) + 1;
        if(x >= y) {
            ans = (mini + y - 1);
        }
        else {
            ans = (mini + y - 1) + (y - x);
        }
    }
    return ans;
}
int main() {
    cin >> t;
    vector<ll> ans(t);
    for(int i = 0; i < t; i++) {
        cin >> y >> x;
        ans[i] = f();
    }
    for(auto i : ans) {
        cout << i << endl;
    }
    return 0;
}