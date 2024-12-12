#include <iostream>
#include <vector>
using namespace std;

int findPeakElement(vector<int>& nums) {
        int s = 0, e = nums.size() - 1;
        int mid = s + (e - s) / 2;
        while(s <= e) {
            if((mid == 0 || nums[mid - 1] < nums[mid]) &&
            (mid == nums.size() - 1 || nums[mid + 1] < nums[mid])) {
                break;
            }
            if(mid == 0 || nums[mid + 1] >= nums[mid - 1]) {
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
            mid = s + (e - s) / 2;
        }
        return mid;
    }

int main() {
    vector<int> nums = {1,2,1,3,5,6,4};
    cout << findPeakElement(nums);
    return 0;
}