#include <iostream>
#include <vector>
using namespace std;

/*

Given a binary array nums and an integer k,
return the maximum number of consecutive 1's
in the array if you can flip at most k 0's.

*/

int longestOnes(vector<int>& nums, int k) {
    int numZeroes = 0;
    int maxLen = 0;
    int i = 0, j = 0;
    while(j < nums.size()) {
        if(nums[j] == 0) numZeroes++;
        j++;
        while(numZeroes > k) {
            maxLen = max(maxLen, j - i - 1);
            if(nums[i] == 0) numZeroes--;
            i++;
        }
        maxLen = max(maxLen, j - i);
    }
    return maxLen;
}

int main() {
    vector<int> nums = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    cout << longestOnes(nums, 3);
    return 0;
}