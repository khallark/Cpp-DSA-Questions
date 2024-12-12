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
#define REP(x, y) for(int i = x; i < y; i++)
#define REPR(x, y) for(int i = x; i >= y; i--)
#define vin(v) for(auto& i : v)
#define vout(v) for(auto i : v)
using namespace std;

ll n;
vll nums;
ll f(int index, ll g1, ll g2) {
    if(index == nums.size()) {
        return abs(g1 - g2);
    }
    return min(f(index + 1, g1 + nums[index], g2), f(index + 1, g1, g2 + nums[index]));
}
int main() {
    cin >> n;
    nums.resize(n);
    vin(nums) cin >> i;
    cout << f(0, 0, 0) << endl;
    return 0;
}