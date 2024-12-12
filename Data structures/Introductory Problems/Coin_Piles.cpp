#include <iostream>
#include <vector>
#define ll long long
#define pii pair<int, int>
using namespace std;

int main() {
    ll t;
    cin >> t;
    ll a, b;
    vector<int> ans(t);
    for(auto& i : ans) {
        cin >> a >> b;
        ll larger = max(a, b);
        ll smaller = min(a, b);
        ll diff = larger - smaller;
        larger -= 2 * diff;
        smaller -= diff;
        if(smaller < 0) i = false;
        else if(larger % 3 == 0) i = true;
    }
    for(auto i : ans) {
        if(i) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}