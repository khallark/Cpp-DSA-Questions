#include <iostream>
#include <vector>
using namespace std;

/*
Given a list of NO-OVERLAPPING Intervals, Insert a new interval into the list.
The new interval may be overlapping with the other intervals.
*/
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    int n = intervals.size();
    vector<vector<int>> ans;
    if(n == 0) return {newInterval}; // if the interval list is empty, insert the new interval and return it.
    if(newInterval[1] < intervals[0][0]) { // if the new interval is to be inserted at the beggining, insert and return.
        ans.push_back(newInterval);
        for(auto& i : intervals) ans.push_back(i);
        return ans;
    }

    int ind = 0;
    int mini = newInterval[0], maxi = newInterval[1];

    while(ind < n && intervals[ind][1] < newInterval[0]) { // keep inserting those intervals from the list, which are not overlapping with the new interval.
        ans.push_back(intervals[ind]);
        if(ind < n - 1 && intervals[ind + 1][0] > newInterval[1]) { // if you find that the new interval can be fitted between the two intervals, insert it ans return.
            ans.push_back(newInterval);
            ind++;
            while(ind < n) ans.push_back(intervals[ind++]);
            return ans;
        }
        ind++;
    }

    if(ind < n) {
        mini = min(mini, intervals[ind][0]);
        maxi = max(maxi, intervals[ind][1]);
        ind++;
    }
    
    while(ind < n && maxi >= intervals[ind][0]) { // keep merging the intervals, unless its not possible.
        mini = min(mini, intervals[ind][0]);
        maxi = max(maxi, intervals[ind][1]);
        ind++;
    }

    ans.push_back({mini, maxi}); // insert the merged interval.

    while(ind < n) { // insert the intervals remaining in the list.
        ans.push_back(intervals[ind]);
        ind++;
    }
    return ans;
}

int main() {
    vector<vector<int>> intervals = {{1,2}, {3,5}, {6,7}, {8,10}, {12,16}};
    vector<int> newInterval = {4,8};
    for(auto i : insert(intervals, newInterval)) {
        cout << "{" << i[0] << "," << i[1] << "} ";
    }
    return 0;
}