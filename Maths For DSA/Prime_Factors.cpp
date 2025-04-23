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
    ll n;
    cin >> n;
    vector<ll> pfs;
    for(ll i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            pfs.push_back(i);
            while(n % i == 0) {
                n /= i;
            }
        }
    }
    if(n != 1) pfs.push_back(n);
    for(auto i : pfs) cout << i << " ";
    return 0;
}