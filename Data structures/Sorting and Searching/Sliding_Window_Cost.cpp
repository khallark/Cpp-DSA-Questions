#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

/*

The median is the middle value in an ordered integer list.
If the size of the list is even, there is no middle value.
So the median is the mean of the two middle values.

For examples, if arr = [2,3,4], the median is 3.
For examples, if arr = [1,2,3,4], the median is (2 + 3) / 2 = 2.5.

You are given an integer array nums and an integer k. There
is a sliding window of size k which is moving from the very
left of the array to the very right. You can only see the k
numbers in the window. Each time the sliding window moves right
by one position.

Return the median array for each window in the original array.
Answers within 10-5 of the actual value will be accepted.

*/

class MedianFinder {
private:
    multiset<int> maxHeap; 
    multiset<int> minHeap; 

public:
    MedianFinder() {}

    void addNum(int num) {
        maxHeap.insert(num);

        if (!minHeap.empty() && *maxHeap.rbegin() > *minHeap.begin()) {
            minHeap.insert(*maxHeap.rbegin());
            maxHeap.erase(--maxHeap.end());
        }

        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.insert(*maxHeap.rbegin());
            maxHeap.erase(--maxHeap.end());
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.insert(*minHeap.begin());
            minHeap.erase(minHeap.begin());
        }
    }

    void removeNum(int num) {
        if (maxHeap.count(num) > 0) {
            maxHeap.erase(maxHeap.find(num)); 
        } else if (minHeap.count(num) > 0) {
            minHeap.erase(minHeap.find(num)); 
        }

        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.insert(*maxHeap.rbegin());
            maxHeap.erase(--maxHeap.end());
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.insert(*minHeap.begin());
            minHeap.erase(minHeap.begin());
        }
    }

    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return *maxHeap.rbegin(); 
        } else {
            return (double(*maxHeap.rbegin()) + double(*minHeap.begin())) / 2.0; 
        }
    }
};


vector<int> medianSlidingWindow(vector<int>& nums, int k) {
    MedianFinder m;
    vector<int> ans;
    int j = 0;
    int sum_cost = 0;
    for(j = 0; j < k; j++) {
        m.addNum(nums[j]);
    }
    for(int i = 0; i < k; i++) {
        sum_cost = abs(arr)
    }
    ans.push_back(sum_cost - k * m.findMedian());
    while(j < nums.size()) {
        m.removeNum(nums[j - k]);
        m.addNum(nums[j]);
        ans.push_back(m.findMedian());
        j++;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(auto& i : nums) cin >> i;
    vector<int> ans = medianSlidingWindow(nums, k);
    for(auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}