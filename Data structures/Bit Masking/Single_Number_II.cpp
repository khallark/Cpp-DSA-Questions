#include <iostream>
#include <vector>
using namespace std;

/*
Given an integer array nums where every element appears three
times except for one, which appears exactly once. Find the
single element and return it.
*/

int singleNumber(vector<int>& nums) {
    int ans = 0;
    for(int i = 0; i < 32; i++) {
        int sum = 0;
        int mask = 1 << i;
        for(auto j : nums) {
            sum += (j & mask) >> i;
        }
        ans |= ((sum % 3) << i);
    }
    return ans;
}

int main() {
    vector<int> nums = {0, 1, 0, 1, 0, 1, 99};
    cout << singleNumber(nums);
    return 0;
}