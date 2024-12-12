#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto& i : arr) cin >> i;
    multiset<int> towers;
    towers.insert(arr[0]);
    for(int i = 1; i < n; i++) {
        auto it = towers.upper_bound(arr[i]);
        if(it != towers.end()) {
            towers.erase(it);
        }
        towers.insert(arr[i]);
    }
    cout << towers.size() << endl;
    return 0;
}