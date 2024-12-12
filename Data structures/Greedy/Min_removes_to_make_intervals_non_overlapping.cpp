#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    int ans = 0;
    int min_end = intervals[0][1];
    for(int i = 1; i < intervals.size(); i++) {
        if(min_end > intervals[i][0]) {
            min_end = min(min_end, intervals[i][1]);
            ans++;
        }
        else {
            min_end = intervals[i][1];
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << eraseOverlapIntervals(intervals) << endl;
    return 0;
}