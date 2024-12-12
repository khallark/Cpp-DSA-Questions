#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
int findPairs(vector<int>& nums, int k) {
    int output = 0;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size() - 1; i++) {
        if(i != 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        int n = fabs(nums[i]) + k;
        int s = i + 1;
        int e = nums.size() - 1;
        int mid = s + (e - s) / 2;
        while(s <= e) {
            if(n == nums[mid]) {
                output++;
                break;
            }
            else if(n > nums[mid]) {
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
            mid = s + (e - s) / 2;
        }
    }
    return output;
}
int main() {
    vector<int> nums = {-2134, -3234, 234, 56754, 345432, -324, 43543, 5345};
    int k = 20;
    cout << findPairs(nums, k) << endl;
    return 0;
}