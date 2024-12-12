#include <iostream>
#include <vector>
using namespace std;
void heapify(vector<int>& v, int i) {
    int n = v.size();
    while(i < n) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if(left < n && v[largest] < v[left]) {
            largest = left;
        }
        if(right < n && v[largest] < v[right]) {
            largest = right;
        }

        if(largest != i) {
            swap(v[largest], v[i]);
            i = largest;
        }
        else {
            return;
        }
    }
}
void convert_to_max_heap(vector<int>& v) {
    for(int i = (v.size() - 1) / 2; i >= 0; i--) {
        heapify(v, i);
    }
}
int main() {
    vector<int> v = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    convert_to_max_heap(v);
    for(auto i : v) {
        cout << i << " ";
    }
    return 0;
}