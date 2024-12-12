#include <iostream>
#include <vector>
using namespace std;

/*

Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
A subarray is a contiguous part of the array.

*/

int f(vector<int>& nums, int goal) { // This function counts the number of subarrays, which are <= goal
    if(goal < 0) return 0;
    int sum = 0;
    int count = 0;
    int i = 0, j = 0;
    while(j < nums.size()) {
        sum += nums[j];
        while(sum > goal) {
            sum -= nums[i];
            i++;
        }
        count += j - i + 1;
        j++;
    }
    return count;
}
int numSubarraysWithSum(vector<int>& nums, int goal) {
    return f(nums, goal) - f(nums, goal - 1); // Simple set theory : Set{0, goal} - Set{0, goal - 1} = Set{goal} (Ans)
}

int main() {
    vector<int> nums = {0,0,0,0,0};
    cout << numSubarraysWithSum(nums, 0) << endl;
    return 0;
}