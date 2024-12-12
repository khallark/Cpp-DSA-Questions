#include <iostream>
#include <queue>
using namespace std;

/*

You have k lists of sorted integers in non-decreasing order.
Find the smallest range that includes at least one number from
each of the k lists.

We define the range [a, b] is smaller than range [c, d] if
(b - a < d - c) or (a < c if b - a == d - c).

*/

vector<int> smallestRange(vector<vector<int>>& nums) {
    int maxi = INT_MIN;
    priority_queue<vector<int>,vector<vector<int>>,
    greater<vector<int>>> minHeap;
    for(int i = 0; i < nums.size(); i++) {
        minHeap.push({nums[i][0], i, 0});
        maxi = max(maxi, nums[i][0]);
    }
    int minA = minHeap.top()[0], minB = maxi;
    while(!minHeap.empty()) {
        vector<int> temp = minHeap.top();
        int i = temp[1], j = temp[2];
        minHeap.pop();
        if(j == nums[i].size()) break;
        minHeap.push({nums[i][j], i, j + 1});
        maxi = max(maxi, nums[i][j]);
        if(minHeap.top()[0] <= maxi && (maxi - minHeap.top()[0]) < (minB - minA)) {
            minA = minHeap.top()[0], minB = maxi;
        }
    }
    return {minA, minB};
}

int main() {
    vector<vector<int>> nums = {
        {4, 10, 15, 24,26},
        {0, 9, 12, 20},
        {5, 18, 22, 30}
    };
    vector<int> ans = smallestRange(nums);
    cout << "[" << ans[0] << ", " << ans[1] << "]";
    return 0;
}