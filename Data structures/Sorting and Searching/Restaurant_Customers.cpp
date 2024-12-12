#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> times;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        times.push_back({x, 1});
        times.push_back({y, -1});
    }
    sort(times.begin(), times.end());
    int count = 0;
    int maxCount = 0;
    for(auto i : times) {
        count += i[1];
        maxCount = max(maxCount, count);
    }
    cout << maxCount << endl;
    return 0;
}