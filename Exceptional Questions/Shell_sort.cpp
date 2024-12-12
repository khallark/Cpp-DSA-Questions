#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void shell_sort(vector<int> &v) {
    int size = v.size() / 2;
    int ptr1 = 0, ptr2 = size;
    while(size) {
        ptr1 = 0, ptr2 = size;
        while(ptr2 < v.size()) {
            if(v[ptr1] > v[ptr2]) {
                swap(v[ptr1], v[ptr2]);
            }
            ptr1++, ptr2++;
        }
        size = size / 2;
    }
}

int main() {
    vector<int> v = {5, 2, 8, 3, 9 ,1, 7, 4};
    shell_sort(v);
    for(auto i : v) {
        cout << i << " ";
    }
    return 0;
}