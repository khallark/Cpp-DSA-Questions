#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

int minimumEffortPath(vector<vector<int>>& heights) {
    int m = heights.size(), n = heights[0].size();
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<vector<int>> efforts(m, vector<int>(n, INT_MAX));
    vector<vector<int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    efforts[0][0] = 0;
    pq.push({0, 0, 0});
    while(!pq.empty()) {
        vector<int> temp = pq.top();
        pq.pop();
        int effort = temp[0], i = temp[1], j = temp[2];
        if(i == m - 1 && j == n - 1) return effort;
        for(auto k : dirs) {
            int I = i + k[0], J = j + k[1];
            if(I >= 0 && I < m && J >= 0 && J < n) {
                int newEffort = max(effort, abs(heights[i][j] - heights[I][J]));
                if(newEffort < efforts[I][J]) {
                    efforts[I][J] = newEffort;
                    pq.push({newEffort, I, J});
                }
            }
        }
    }
    return 0;
}

int main() {
    vector<vector<int>> heights = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}
    };
    cout << minimumEffortPath(heights) << endl;
    return 0;
}