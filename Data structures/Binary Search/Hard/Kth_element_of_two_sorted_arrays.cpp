#include <iostream>
#include <vector>
#include <climits>
using namespace std;

float kthElement(vector<int>& arr1, vector<int>& arr2, int k) {
    vector<int> smaller = arr1.size() <= arr2.size() ? arr1 : arr2;
    vector<int> bigger = arr1.size() > arr2.size() ? arr1 : arr2;

    int l1, r1, l2, r2;
    int s = max(0, int(k - bigger.size())), e = min(k, int(smaller.size()));
    int mid = s + (e - s) / 2;
    float median = 0;

    while(s <= e) {
        int mid1 = mid;
        int mid2 = k - mid;

        l1 = (mid1 > 0 && mid1 <= smaller.size()) ? (smaller[mid1 - 1]) : (INT_MIN);
        r1 = (mid1 >= 0 && mid1 < smaller.size()) ? (smaller[mid1]) : (INT_MAX);
        l2 = (mid2 > 0 && mid2 <= bigger.size()) ? (bigger[mid2 - 1]) : (INT_MIN);
        r2 = (mid2 >= 0 && mid2 < bigger.size()) ? (bigger[mid2]) : (INT_MAX);
        
        if(l1 <= r2 && l2 <= r1) {
            median = max(l1, l2);
            break;
        }
        else if(l1 > r2) {
            e = mid - 1;
        }
        else if(l2 > r1) {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return median;
}

int main() {
    vector<int> arr1 = {1, 3, 4, 7, 10, 12};
    vector<int> arr2 = {2, 3, 6, 15, 16};
    for(int i = 0; i < 11; i++) {
        cout << kthElement(arr1, arr2, i + 1) << " ";
    }
    return 0;
}