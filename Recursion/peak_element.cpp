#include <iostream>
#include <vector>
using namespace std;
int peakElement(vector<int>arr, int s, int e, int size) {
    if(size == 1) return 0;
    int mid = s + (e - s) / 2;
    int indx;
    if((mid - 1 == -1 || arr[mid] > arr[mid - 1]) && (mid + 1 == size + 1 || arr[mid] > arr[mid + 1]))
        return mid;
    else if(mid - 1 != -1 && arr[mid - 1] > arr[mid])
        indx = peakElement(arr, s, mid - 1, size);
    else if(mid + 1 != size && arr[mid + 1] > arr[mid])
        indx = peakElement(arr, mid + 1, e, size);
    return indx;
}
int findPeakElement(vector<int>& nums) {
    return peakElement(nums, 0, nums.size() - 1, nums.size());
}
int main() {
    vector<int>arr = {1};
    cout << arr[findPeakElement(arr)] << endl;
    return 0;
}