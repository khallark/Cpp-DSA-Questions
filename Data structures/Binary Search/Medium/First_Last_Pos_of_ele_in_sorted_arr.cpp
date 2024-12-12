#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Given an array of integers nums sorted in non-decreasing order,
// find the starting and ending position of a given target value.
// If target is not found in the array, return [-1, -1].
vector<int> searchRange(vector<int>& nums, int target) {
    int LB = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    if(LB == nums.size() || nums[LB] != target) return {-1, -1};
    int UB = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
    return {LB, UB};
}
int main() {
    vector<int> nums = {5,7,7,8,8,10};
    for(auto i : searchRange(nums, 6)) {
        cout << i << " ";
    }
    return 0;
}