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
    for(int i = 0; i < n; i++) {
        ll sum = x - nums[i].first;
        int j = i + 1;
        int k = n - 1;
        if(sum <= 0) continue;
        while(j < k) {
            if(nums[j].first + nums[k].first == sum) break;
            else if(nums[j].first + nums[k].first < sum) j++;
            else k--;
        }
        if(j < k) {
            ans = {nums[i].second, nums[j].second, nums[k].second};
            sort(ans.begin(), ans.end());
            break;
        }
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