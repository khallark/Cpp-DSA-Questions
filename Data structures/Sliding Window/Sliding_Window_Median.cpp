#include <iostream>
#include <vector>
#include <set>
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


vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    MedianFinder m;
    vector<double> ans;
    int j = 0;
    for(j = 0; j < k; j++) {
        m.addNum(nums[j]);
    }
    ans.push_back(m.findMedian());
    while(j < nums.size()) {
        m.removeNum(nums[j - k]);
        m.addNum(nums[j]);
        ans.push_back(m.findMedian());
        j++;
    }
    return ans;
}

int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    for(auto i : medianSlidingWindow(nums, 3)) {
        cout << i << " ";
    }
    return 0;
}