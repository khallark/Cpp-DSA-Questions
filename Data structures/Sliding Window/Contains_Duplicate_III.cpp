#include <iostream>
#include <set>
#include <vector>
using namespace std;

/*

You are given an integer array nums and two integers indexDiff and valueDiff.

Find a pair of indices (i, j) such that: 
 - i != j
 - abs(i - j) <= indexDiff.
 - abs(nums[i] - nums[j]) <= valueDiff, and

Return true if such pair exists or false otherwise.

*/

bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
    set<int> sorted;
    for(int i = 0; i < nums.size(); i++) {
        auto lower = sorted.lower_bound(nums[i] - valueDiff);
        if(lower != sorted.end() && abs(nums[i] - *lower) <= valueDiff) {
            return true;
        }
        sorted.insert(nums[i]);
        if(sorted.size() > indexDiff) {
            sorted.erase(nums[i - indexDiff]);
        }
    }
    return false;
}

int main() {
    vector<int> nums = {1, 2, 3, 1};
    cout << containsNearbyAlmostDuplicate(nums, 3, 0);
    return 0;
}