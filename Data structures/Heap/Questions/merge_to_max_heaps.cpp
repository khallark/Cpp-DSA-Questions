#include <iostream>
#include <vector>
using namespace std;
vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
    vector<int> merged(m + n);

    int index = 0;

    for(int i = 0; i < n; i++) {
        int ind = index++;
        merged[ind] = a[i];
        int parent = ind&1 ? ind / 2 : (ind / 2) - 1;
        while(parent >= 0) {
            if(merged[parent] < merged[ind]) {
                swap(merged[parent], merged[ind]);
                ind = parent;
                parent = parent&1 ? parent / 2 : (parent / 2) - 1;
            }
            else {
                break;
            }
        }
    }
    for(int i = 0; i < m; i++) {
        int ind = index++;
        merged[ind] = b[i];
        int parent = ind&1 ? ind / 2 : (ind / 2) - 1;
        while(parent >= 0) {
            if(merged[parent] < merged[ind]) {
                swap(merged[parent], merged[ind]);
                ind = parent;
                parent = parent&1 ? parent / 2 : (parent / 2) - 1;
            }
            else {
                break;
            }
        }
    }
    return merged;
}
int main() {
    vector<int> a = {10, 5, 2, 6};
    vector<int> b = {12, 7, 9};
    vector<int> merged = mergeHeaps(a, b, a.size(), b.size());
    for(auto i : merged) {
        cout << i << " ";
    }
    return 0;
}