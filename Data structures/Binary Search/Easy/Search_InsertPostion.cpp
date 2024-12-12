#include <iostream>
#include <vector>
using namespace std;

// Given a sorted array of distinct integers and
// a target value, return the index if the target
// is found. If not, return the index where it
// would be if it were inserted in order.

int searchInsert(vector<int>& nums, int target) {
    return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
}
int main() {
    vector<int> arr = {1, 3, 5, 6};

}