#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Smallest Index, such that arr[Index] >= n, where n = someValue.
int LB(vector<int>& arr, int n) {
    int s = 0, e = arr.size() - 1;
    int mid = s + (e - s) / 2;
    int ans = arr.size();
    while(s <= e) {
        if(arr[mid] >= n) {
            ans = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

// Smallest Index, such that arr[Index] > n, where n = someValue.
int UB(vector<int>& arr, int n) {
    int s = 0, e = arr.size() - 1;
    int mid = s + (e - s) / 2;
    int ans = arr.size();
    while(s <= e) {
        if(arr[mid] > n) {
            ans = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}


int main() {
    vector<int> arr = {5,7,7,8,8,10};
    cout << lower_bound(arr.begin(), arr.end(), 6) - arr.begin();
    return 0;
}