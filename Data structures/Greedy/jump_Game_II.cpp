#include <iostream>
#include <vector>
using namespace std;
int MinJumps(vector<int>& nums) {
    if(nums.size() == 1) return 0;

    vector<pair<int, int>> maxs;
    int maxi = nums[0];
    maxs.push_back({maxi, 0});

    for(int i = 0; i < nums.size(); i++) {
        int temp = max(maxi, i + nums[i]);
        if(maxi != temp) {
            maxi = temp;
            maxs.push_back({maxi, i});
        }
    }

    if(maxs.back().second != nums.size() - 1) maxs.push_back({maxi, nums.size() - 1});

    int i = 1;
    maxi = maxs[0].first;
    bool got = false;
    int ans = 0;
    while(i < maxs.size()) {
        if(maxi < maxs[i].second) {
            maxi = maxs[i - 1].first;
            ans++;
        } i++;
    }

    return ans + 1;
}

int main() {
    vector<int> jumps = {3, 2, 1, 0, 4};
    cout << MinJumps(jumps);
    return 0;
}