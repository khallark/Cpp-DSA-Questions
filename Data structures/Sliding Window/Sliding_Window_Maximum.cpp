#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*

You are given an array of integers nums, there is a sliding window
of size k which is moving from the very left of the array to the
very right. You can only see the k numbers in the window. Each time
the sliding window moves right by one position.

Return the max sliding window.

*/


// Time Complexity : O(N.logK)
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    ios::sync_with_stdio(0);
    map<int, int, greater<int>> m;
    int maxi = INT_MIN;
    int j;
    for(j = 0; j < k; j++) {
        maxi = max(maxi, nums[j]);
        m[nums[j]]++;
    }
    vector<int> ans;
    ans.push_back(m.begin()->first);
    while(j < nums.size()) {
        m[nums[j - k]]--;
        if(m[nums[j - k]] == 0) m.erase(nums[j - k]);
        m[nums[j]]++;
        ans.push_back(m.begin()->first);
        j++;
    }
    return ans;
}

int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    for(auto i : maxSlidingWindow(nums, 3)) {
        cout << i << " ";
    }
    return 0;
}