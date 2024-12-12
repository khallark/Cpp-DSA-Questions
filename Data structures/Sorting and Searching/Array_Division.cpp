#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int n, k;
vector<int> nums;
ll sum = 0;
ll e, s, mid;

bool posSol(ll mid) {
    int subarray = 1;
    ll curr_sum = 0;
    for(auto num : nums) {
        if(curr_sum + (ll)num > mid) {
            subarray++;
            curr_sum = num;
            if(subarray > k) {
                return false;
            }
        } else {
            curr_sum += (ll)num;
        }
    }
    return true;
}

int main() {
    cin >> n >> k;
    nums.resize(n);
    for(auto& i : nums) {
        cin >> i;
        sum += i;
    }
    s = *max_element(nums.begin(), nums.end());
    e = sum;
    ll ans;
    while(s <= e) {
        mid = s + (e - s) / 2;
        if(posSol(mid)) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}