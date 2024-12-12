#include <iostream>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;
int fast_expo(int x, int n) {
    int res = 1;
    while(n > 0) {
        if(n&1) res = ((ll)res * (ll)x) % MOD;
        x = ((ll)x * (ll)x) % MOD;
        n = ((ll)n >> 1) % MOD;
    }
    return res;
}
int main() {
    int n;
    cin >> n;
    cout << fast_expo(2, n);
    return 0;
}