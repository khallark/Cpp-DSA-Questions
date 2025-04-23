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
    auto gcd1 = [&](ll a, ll b) {
        ll sn = min(a, b);
        ll bn = max(a, b);
        ll gcd = 1;
        for(ll i = 1; i * i <= sn; i++) {
            if(sn % i == 0) {
                if(bn % i == 0) gcd = max(gcd, i);
                if(bn % (sn / i) == 0) gcd = max(gcd, sn / i);
            }
        }
        cout << gcd << endl;
    };
    auto gcd2 = [&](ll a, ll b) {
        while(a && b) {
            if(a >= b) a = a % b;
            else b = b % a;
        }
        cout << max(a, b) << endl;
    };
    ll n1, n2;
    cin >> n1 >> n2;
    gcd1(n1, n2); // O ( √ min ( a , b ) )
    gcd2(n1, n2); // O ( log ᵩ ( min ( a , b ) ) )
    return 0;
}