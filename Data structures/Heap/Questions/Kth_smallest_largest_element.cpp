#include <iostream>
#include <queue>
using namespace std;
int kthSmallest(int arr[], int l, int r, int k) {
    priority_queue<int> maxHeap;
    for(int i = 0; i <= r; i++) {
        maxHeap.push(arr[i]);
        if(maxHeap.size() > k) {
            maxHeap.pop();
        }
    }
    return maxHeap.top();
}
int kthLargest(int arr[], int l, int r, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int i = 0; i <= r; i++) {
        minHeap.push(arr[i]);
        if(minHeap.size() > k) {
            minHeap.pop();
        }
    }
    return minHeap.top();
}
int main() {
    int arr[] = {7, 10, 1, 3, 9, 5, 8};
    int l = 0;
    int r = sizeof(arr) / sizeof(int) - 1;
    cout << kthLargest(arr, l, r, 1);
}