#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int, int>
#define pll pair<ll, ll>
#define REP(i, x, y) for(int i = x; i < y; i++)
#define REPR(i, x, y) for(int i = x; i >= y; i--)
using namespace std;

int nthUglyNumber(int N, int A, int B, int C) {
    auto GCD = [&](ll a, ll b) {
        while(a && b) {
            if(a >= b) a %= b;
            else b %= a;
        }
        return max(a, b);
    };

    auto LCM = [&](ll a, ll b) {
        return (a / GCD(a, b)) * b;
    };

    ll a = A, b = B, c = C;
    ll n = N;
    ll low = 1, high = 2e9;

    while(low < high) {
        ll mid = (low + high) / 2;
        ll ab = LCM(a, b);
        ll bc = LCM(b, c);
        ll ac = LCM(a, c);
        ll abc = LCM(a, bc);

        ll o = (mid / a) + (mid / b) + (mid / c)
            - (mid / ab) - (mid / bc) - (mid / ac)
            + (mid / abc);

        if(o < n) low = mid + 1;
        else high = mid;
    }

    return low;
}

int main() {
    int n = 5, a = 2, b = 11, c = 13;
    cout << nthUglyNumber(n, a, b, c);
    return 0;
}