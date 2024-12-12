#include <iostream>
#include <vector>
using namespace std;

/*

An integer array is called arithmetic if it consists of at
least three elements and if the difference between any two
consecutive elements is the same.

For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are
arithmetic sequences.

Given an integer array nums, return the number of arithmetic
subarrays of nums.

A subarray is a contiguous subsequence of the array.

*/

int numberOfArithmeticSlices(vector<int>& nums) {
    if(nums.size() < 3) return 0;
    int diff = nums[1] - nums[0];
    int count = 0;
    int i = 0, j = 2;
    while(j < nums.size()) {
        if(nums[j] - nums[j - 1] == diff) {
            count += j - i - 1;
        } else {
            i = j - 1;
            diff = nums[j] - nums[j - 1];
        }
        j++;
    }
    return count;
}

int main() {
    vector<int> nums = {1,2,3,8,9,10};
    cout << numberOfArithmeticSlices(nums);
    return 0;
}