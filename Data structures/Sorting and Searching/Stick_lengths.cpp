#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<ll> nums(n);
    for(auto& i : nums) cin >> i;
    sort(nums.begin(), nums.end());
    ll value = nums[n / 2];
    ll sum = 0;
    for(auto i : nums) {
        sum += abs(i - value);
    }
    cout << sum << endl;
    return 0;
}