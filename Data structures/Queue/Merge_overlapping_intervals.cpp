#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());
    int n = 0;
    while(n < intervals.size()) {
        int s = intervals[n][0]; // the starting point of the current interval, whatsoever.
        int max = intervals[n][1]; // helps in interpreting the biggest interval till the current. iteration.
        while(n < intervals.size() && max >= intervals[n][0]) {
            max = intervals[n][1] > max ? intervals[n][1] : max;
            n++;
        }
        ans.push_back({s, max}); // storing the largest current interval.
    }
    return ans;
}
int main() {
    vector<vector<int>> a = {{1, 8}, {5, 7}, {2, 3}, {4, 9}, {1, 5}, {6, 19}, {17, 18}, {5, 8}};
    vector<vector<int>> ans = overlappedInterval(a);
    sort(a.begin(), a.end());
    cout << "[";
    for(int i = 0; i < a.size(); i++) {
        cout << "[" << a[i][0] << "," << a[i][1] << "]";
        if(i < a.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;
    cout << "[";
    for(int i = 0; i < ans.size(); i++) {
        cout << "[" << ans[i][0] << "," << ans[i][1] << "]";
        if(i < ans.size() - 1) {
            cout << ",";
        }
    }
    cout << "]";
    return 0;
}