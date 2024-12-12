#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int maxMeetings(int n, int start[], int end[]) {
    vector<vector<int>> time(n);
    for(int i = 0; i < n; i++) {
        time[i] = {start[i], end[i]};
    }
    sort(time.begin(), time.end());
    int ans = 1;
    int min_end_time = time[0][1];
    for(int i = 1; i < n; i++) {
        if(min_end_time >= time[i][0]) {
            min_end_time = min(min_end_time, time[i][1]);
        }
        else {
            min_end_time = time[i][1];
            ans++;
        }
    }
    return ans;
}

int main() {
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(start) / sizeof(start[0]);
    cout << maxMeetings(n, start, end) << endl;
    return 0;
}