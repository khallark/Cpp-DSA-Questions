#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

float Median_2_sorted_arrs(vector<int> arr1, vector<int> arr2) {
    int l1, l2, r1, r2;


    vector<int> smaller = arr1.size() <= arr2.size() ? arr1 : arr2;
    vector<int> larger = arr1.size() > arr2.size() ? arr1 : arr2;


    int size = arr1.size() + arr2.size();


    int s = 0;
    int e = min(arr1.size(), arr2.size());
    int mid = s + (e - s) / 2;


    float median = 0;
    while(s <= e) {
        // Step 1:
        int mid1 = mid;
        int mid2 = size / 2 - mid;

        l1 = (mid1 > 0 && mid1 <= smaller.size()) ? (smaller[mid1 - 1]) : (INT_MIN);
        r1 = (mid1 >= 0 && mid1 < smaller.size()) ? (smaller[mid1]) : (INT_MAX);
        l2 = (mid2 > 0 && mid2 <= larger.size()) ? (larger[mid2 - 1]) : (INT_MIN);
        r2 = (mid2 >= 0 && mid2 < larger.size()) ? (larger[mid2]) : (INT_MAX);



        // Step 2:
        if(l1 <= r2 && l2 <= r1) {
            if((arr1.size() + arr2.size())&1) {
                median = min(r1, r2);
            }
            else {
                median = (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            break;
        }
        else if(l1 > r2) {
            e = mid - 1;
        }
        else if(l2 > r1) {
            s = mid + 1;
        }


        // Step 3:
        mid = s + (e - s) / 2;
    }


    return median;
}

int main() {
    vector<int> arr1 = {2};
    vector<int> arr2 = {1};
    cout << Median_2_sorted_arrs(arr1, arr2);
    return 0;
}