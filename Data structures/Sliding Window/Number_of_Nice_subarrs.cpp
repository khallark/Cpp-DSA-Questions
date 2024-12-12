#include <iostream>
#include <vector>
using namespace std;

/*

Given an array of integers nums and an integer k.
A continuous subarray is called nice if there are
k odd numbers on it.

Return the number of nice sub-arrays.

*/

int numberOfSubarrays(vector<int>& nums, int k) {
    int numOdds = 0;
    int firstOdd = -1;
    int count = 0;
    int i = 0, j = 0;
    while(j < nums.size()) {
        if(nums[j] & 1) {
            numOdds++;
            if(firstOdd == -1) firstOdd = j;
        }
        if(numOdds > k) {
            numOdds--;
            i = firstOdd + 1;
            firstOdd++;
            while(firstOdd < nums.size() &&
            !(nums[firstOdd] & 1)) firstOdd++;
        }
        if(numOdds == k) count += firstOdd - i + 1;
        j++;
    }
    return count;
}

int main() {
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    cout << numberOfSubarrays(nums, 1);
    return 0;
}