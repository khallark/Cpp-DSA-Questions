#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> revAfterPos(vector<int> arr, int m) {
    int left = m + 1;
    int right = arr.size() - 1;
    while(left < right) {
        swap(arr.at(left++), arr.at(right--));
    }
    return arr;
}
int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6};
    // cout << v.size() << endl;
    vector<int> arr = revAfterPos(v, 0);
    for(int i:arr) {
        cout << i << " ";
    }
    reverse(v.begin(), v.begin() + 2);
    return 0;
}