#include <iostream>
#include <vector>
using namespace std;

class Search_in_Rotated_Sorted_Array {
public:
    int array_with_unique_elements(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;
        int mid = s + (e - s) / 2;
        while(s <= e) {
            if(nums[mid] == target) return mid;
            bool left = nums[s] <= nums[mid];
            bool right = nums[mid] <= nums[e];
            if(left && !right) {
                if(target > nums[mid]) s = mid + 1;
                else {
                    if(target >= nums[s]) e = mid - 1;
                    else s = mid + 1;
                }
            }
            else if(!left && right) {
                if(target < nums[mid]) e = mid - 1;
                else {
                    if(target <= nums[e]) s = mid + 1;
                    else e = mid - 1;
                }
            }
            else {
                if(target < nums[mid]) e = mid - 1;
                else s = mid + 1;
            }
            mid = s + (e - s) / 2;
        }
        return -1;
    }
    bool array_with_duplicate_elements(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;
        int mid = s + (e - s) / 2;
        while(s <= e) {
            if(nums[mid] == target) return true;
            bool left = nums[s] <= nums[mid];
            bool right = nums[mid] <= nums[e];
            if(left && !right) {
                if(target > nums[mid]) s = mid + 1;
                else {
                    if(target >= nums[s]) e = mid - 1;
                    else s = mid + 1;
                }
            }
            else if(!left && right) {
                if(target < nums[mid]) e = mid - 1;
                else {
                    if(target <= nums[e]) s = mid + 1;
                    else e = mid - 1;
                }
            }
            else {
                if(nums[s] == nums[mid] && nums[mid] == nums[e]) s++, e--;
                else if(target < nums[mid]) e = mid - 1;
                else s = mid + 1;
            }
            mid = s + (e - s) / 2;
        }
        return false;
    }
};

int main() {
    vector<int> uniques = {4,5,6,7,0,1,2};
    vector<int> duplicates = {1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1};
    Search_in_Rotated_Sorted_Array ans;
    cout << ans.array_with_unique_elements(uniques, 6) << endl;
    cout << ans.array_with_unique_elements(uniques, 8) << endl;
    cout << ans.array_with_duplicate_elements(duplicates, 2) << endl;
    cout << ans.array_with_duplicate_elements(duplicates, 3) << endl;
    return 0;
}