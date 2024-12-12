#include <iostream>
#include <vector>
#include <climits>
using namespace std;

float median(vector<int>& arr1, vector<int>& arr2) {
    int totalSize = arr1.size() + arr2.size();

    vector<int> smaller = arr1.size() <= arr2.size() ? arr1 : arr2;
    vector<int> bigger = arr1.size() > arr2.size() ? arr1 : arr2;

    int l1, r1, l2, r2;
    int s = 0, e = smaller.size();
    int mid = s + (e - s) / 2;
    float median = 0;

    while(s <= e) {
        int mid1 = mid;
        int mid2 = totalSize / 2 - mid;
        l1 = (mid1 > 0 && mid1 <= smaller.size()) ? (smaller[mid1 - 1]) : (INT_MIN);
        r1 = (mid1 >= 0 && mid1 < smaller.size()) ? (smaller[mid1]) : (INT_MAX);
        l2 = (mid2 > 0 && mid2 <= bigger.size()) ? (bigger[mid2 - 1]) : (INT_MIN);
        r2 = (mid2 >= 0 && mid2 < bigger.size()) ? (bigger[mid2]) : (INT_MAX);
        
        if(l1 <= r2 && l2 <= r1) {
            if(totalSize & 1) {
                median = min(r1, r2);
            }
            else {
                int left = max(l1, l2);
                int right = min(r1, r2);
                median = (left + right) / 2.0;
            }
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
    vector<int> arr1 = {1};
    vector<int> arr2 = {2};
    cout << median(arr1, arr2);
    return 0;
}