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
    auto fast_expo = [&](ll base, ll exp) {
        ll result = 1;
        while(exp) {
            if(exp & 1) result *= base;
            exp >>= 1;
            base *= base;
        }
        return result;
    };
    cout << fast_expo(12, 15);
    return 0;
}