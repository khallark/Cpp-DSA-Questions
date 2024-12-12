#include <iostream>
#include <vector>
using namespace std;

int findPivot(vector<int>& nums) {
    int s = 0, e = nums.size() - 1;
    int mid = s + (e - s) / 2;
    while(nums[s] > nums[mid] || nums[mid] > nums[e]) {
        bool left = nums[s] <= nums[mid];
        bool right = nums[mid] <= nums[e];
        if(left) s = mid + 1;
        else e = mid;
        mid = s + (e - s) / 2;
    }
    return nums.size() - s;
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << findPivot(nums);
    return 0;
}