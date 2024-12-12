#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

//Function to find the minimum number of platforms required at the
//railway station such that no train waits.
int findPlatform(int arr[], int dep[], int n)
{
    vector<vector<int>> times(n);
    for(int i = 0; i < n; i++) {
        times[i] = {arr[i], dep[i]};
    }
    sort(times.begin(), times.end());
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(times[0][1]);
    int ans = 1;
    for(int i = 1; i < n; i++) {
        while(!minHeap.empty() && times[i][0] > minHeap.top()) {
            minHeap.pop();
        }
        minHeap.push(times[i][1]);
        ans = max(ans, int(minHeap.size()));
    }
    return ans;
}

int main() {
    int arr[] = {900, 940, 950, 1100, 1500, 1800}, 
    dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    int n = 6;
    cout << findPlatform(arr, dep, n) << endl;
    return 0;
}