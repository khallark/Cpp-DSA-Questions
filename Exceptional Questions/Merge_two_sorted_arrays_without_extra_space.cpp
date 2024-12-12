#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge(vector<int> &arr1, vector<int> &arr2, int n, int m) {
    int ptr1 = n - 1, ptr2 = 0;

    while(ptr1 >= 0 && ptr2 < m && arr1[ptr1] > arr2[ptr2]) {
        swap(arr1[ptr1--], arr2[ptr2++]);
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
} 

int main() {
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {0, 2, 6, 8, 9};
    int n = arr1.size();
    int m = arr2.size();
    merge(arr1, arr2, n, m);
    for(auto i : arr1) {
        cout << i << " ";
    }
    cout << endl;
    for(auto i : arr2) {
        cout << i << " ";
    }
    return 0;
}