#include <iostream>
#include <vector>
using namespace std;

/*
Given an integer array nums, in which exactly two elements appear only
once and all the other elements appear exactly twice. Find the two elements
that appear only once. You can return the answer in any order.
*/

vector<int> singleNumber(vector<int>& nums) {
    int res = 0;
    for(auto i : nums) res ^= i;
    int firstSetBit = (res & (res - 1)) ^ res;
    int bucket1 = 0;
    int bucket2 = 0;
    for(auto i : nums) {
        if(i & firstSetBit) bucket1 ^= i;
        else bucket2 ^= i;
    }
    return {bucket1, bucket2};
}

int main() {
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 10};
    cout << singleNumber(nums)[0] << ", " << singleNumber(nums)[1];
    return 0;
}