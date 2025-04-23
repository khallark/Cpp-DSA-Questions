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
    while(1) {
        cin >> n;
        if(n == 1) cout << 0 << endl;
        else if(n == 2 || n == 3) cout << 1 << endl;
        else if(n & 1) {
            bool b = true;
            for(ll i = 2; i * i <= n; i++) {
                if(n % i == 0) {
                    b = false;
                    break;
                }
            }
            cout << b << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}