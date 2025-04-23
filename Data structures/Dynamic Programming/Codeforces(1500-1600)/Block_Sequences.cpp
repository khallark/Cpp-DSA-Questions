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

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(auto &i : a) cin >> i;
        vector<int> dp(n + 1);
        for(int i = n - 1; i >= 0; i--) {
            if(i + a[i] + 1 > n) dp[i] = min(1 + dp[i + 1] , n - i);
            else dp[i] = min(1 + dp[i + 1], dp[i + a[i] + 1]);
        }
        cout << dp[0] << endl;
    }
    return 0;
}