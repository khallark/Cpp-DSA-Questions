#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> machines(n);
    int maxTime = 0;
    for(auto& i : machines) {
        cin >> i;
        maxTime = max(maxTime, i);
    }
    ll s = 1, e = static_cast<ll>(t) * maxTime;
    ll ans = -1;
    while(s <= e) {
        ll mid = s + (e - s) / 2;
        ll prodsMade = 0;
        for(auto i : machines) {
            prodsMade += mid / i;
            if(prodsMade >= t) break;
        }
        if(prodsMade >= t) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}