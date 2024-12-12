#include <iostream>
#include <vector>
using namespace std;
int binarySearch(vector<int> arr, int s, int e, int target) {
    int mid = s + (e - s) / 2;
    if(s > e)
        return -1;
    if (target == arr[mid])
        return mid;
    else if(target > arr[mid])
        return binarySearch(arr, mid + 1, e, target);
    else
        return binarySearch(arr, s, mid - 1, target);
}
vector<int> firstLastPos(vector<int>& nums, int k) {
    vector<int> pair;
    int pos = binarySearch(nums, 0, nums.size(), k);
    if(pos == -1) {
        pair.push_back(-1);
        pair.push_back(-1);
    }
    else {
        int a = pos;
        while(a != -1 && nums[a] == nums[pos]) {
            a--;
        }
        pair.push_back(a + 1);
        a = pos;
        while(a < nums.size() && nums[a] == nums[pos]) {
            a++;
        }
        pair.push_back(a - 1);
    }
    return pair;
}
int findTotalOccurs(vector<int> nums, int k) {
    vector<int> pair = firstLastPos(nums, k);
    if(pair[0] == -1) {
        return 0;
    }
    else if(pair[0] == pair[1]) {
        return 1;
    }
    return pair[1] - pair[0] + 1;
}
int main() {
    vector<int> nums = {1, 2, 2, 3, 3, 3, 3, 3, 4, 5, 6, 6, 6, 8, 8};
    int size = nums.size();
    vector<int> pair = firstLastPos(nums, 8);
    for(auto i: pair) {
        cout << i << " ";
    }
    cout << endl << findTotalOccurs(nums, 7) << endl;
    return 0;
}