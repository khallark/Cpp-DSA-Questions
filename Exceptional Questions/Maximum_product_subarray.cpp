#include <iostream>
#include <vector>
using namespace std;

int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int prefix = 1, suffix = 1;
    int maxi = INT_MIN;
    bool contains_zeroes = false;
    for(int i = 0; i < n; i++) {
        if(prefix == 0) contains_zeroes = true, prefix = 1;
        if(suffix == 0) contains_zeroes = true, suffix = 1;
        prefix *= nums[i];
        suffix *= nums[n - i - 1];
        maxi = max(maxi, max(prefix, suffix));
    }
    if(maxi < 0 && contains_zeroes) return 0;
    return maxi;
}

int main() {
    vector<int> nums = {-2, 0, -1};
    cout << maxProduct(nums);
    return 0;
}