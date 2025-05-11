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

long long distributeCandies(int n, int limit) {
    if(limit >= n) {
        return (1LL * (1LL + n) * (2LL + n)) / 2LL;
    }
    long long min = 0;
    if(n > 2 * limit) {
        min = n - 2 * limit;
    }
    long long ans = 0;
    for(long long i = min; i <= limit; i++) {
        long long mini = n - i - limit;
        if(mini >= 0) {
            ans += (limit - mini) + 1;  // add freq([mini, limit]) to the ans
        } else {
            ans += (limit + mini) + 1;  // add freq([0, limit + (-mini)]) to the ans
        }
    }
    return ans;
}

int main() {
    cout << distributeCandies(1e6, 1e6);
    return 0;
}