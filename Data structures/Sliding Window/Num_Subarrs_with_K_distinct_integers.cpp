#include <iostream>
#include <vector>
using namespace std;

/*

Given an integer array nums and an integer k,
return the number of good subarrays of nums.

A good array is an array where the number of
different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

*/

// Time Complexity : O(N²)
int subarraysWithKDistinct1(vector<int>& nums, int k) {
    vector<int> m(nums.size() + 1);
    int count = 0;
    int numInts = 0;
    int i = 0, j = 0;
    while(j < nums.size()) {
        if(m[nums[j]] == 0) numInts++;
        m[nums[j]]++;
        while(numInts > k) {
            m[nums[i]]--;
            if(m[nums[i]] == 0) numInts--;
            i++;
        }
        if(numInts == k) {
            int temp = numInts;
            int I = i;
            vector<int> mt = m;
            while(temp == k) {
                mt[nums[I]]--;
                if(mt[nums[I]] == 0) temp--;
                I++;
            }
            count += I - i;
        }
        j++;
    }
    return count;
}


// Time Complexity : O(N)
int f(vector<int>& nums, int k) {
    vector<int> m(nums.size() + 1);
    int count = 0;
    int numInts = 0;
    int i = 0, j = 0;
    while(j < nums.size()) {
        if(m[nums[j]] == 0) numInts++;
        m[nums[j]]++;
        while(numInts > k) {
            m[nums[i]]--;
            if(m[nums[i]] == 0) numInts--;
            i++;
        }
        if(numInts <= k) count += j - i + 1;
        j++;
    }
    return count;
}
int subarraysWithKDistinct2(vector<int>& nums, int k) {
    return f(nums, k) - f(nums, k - 1);
}

int main() {
    vector<int> nums = {1,2,1,2,3};
    cout << subarraysWithKDistinct1(nums, 2) << endl << subarraysWithKDistinct2(nums, 2);
    return 0;
}