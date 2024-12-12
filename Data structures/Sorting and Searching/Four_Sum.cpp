#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define pli pair<ll, int>
using namespace std;

int main() {
    int n;
    ll x;
    cin >> n >> x;
    vector<pli> nums(n);
    int index = 1;
    for(auto& i : nums) {
        cin >> i.first;
        i.second = index++;
    }
    vector<int> ans;
    sort(nums.begin(), nums.end());
    for(int h = 0; h < n; h++) {
        ll sum1 = x - nums[h].first;
        if(sum1 <= 0) continue;
        for(int i = h + 1; i < n; i++) {
            ll sum2 = sum1 - nums[i].first;
            if(sum2 <= 0) continue;
            int j = i + 1;
            int k = n - 1;
            while(j < k) {
                if(nums[j].first + nums[k].first == sum2) break;
                else if(nums[j].first + nums[k].first < sum2) j++;
                else k--;
            }
            if(j < k) {
                ans = {nums[h].second, nums[i].second, nums[j].second, nums[k].second};
                sort(ans.begin(), ans.end());
                break;
            }
        }
        if(!ans.empty()) break;
    }

    if(ans.empty()) cout << "IMPOSSIBLE" << endl;
    else {
        for(auto i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}