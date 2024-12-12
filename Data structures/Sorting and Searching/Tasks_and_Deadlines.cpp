#include <iostream>
#include <vector>
#include <algorithm>
#define fs first
#define sc second
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> ad(n);
    for(auto& i : ad) {
        cin >> i.fs >> i.sc;
    }
    sort(ad.begin(), ad.end());
    ll f = 0;
    ll reward = 0;
    for(auto i : ad) {
        f += i.fs;
        ll d = i.sc;
        reward += d - f;
    }
    cout << reward << endl;
    return 0;
}