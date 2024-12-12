#include <iostream>
#include <vector>
using namespace std;

/*
You are given a sorted array consisting of only
integers where every element appears exactly twice,
except for one element which appears exactly once.
Return the single element that appears only once.
*/

int singleNonDuplicate(vector<int>& nums) {
    int s = 0, e = nums.size() - 1;
    int mid = s + (e - s) / 2;
    while(s <= e) {
        if(mid > 0 && nums[mid - 1] == nums[mid]) {
            if((mid - s + 1)&1) e = mid;
            else s = mid + 1;
        }
        else if(mid < nums.size() - 1 && nums[mid + 1] == nums[mid]) {
            if((mid - s)&1) e = mid - 1;
            else s = mid;
        }
        else {
            break;
        }
        mid = s + (e - s) / 2;
    }
    return nums[mid];
}

int main() {
    vector<int> nums = {1,1,2,3,3,4,4,8,8};
    cout << singleNonDuplicate(nums);
    return 0;
}