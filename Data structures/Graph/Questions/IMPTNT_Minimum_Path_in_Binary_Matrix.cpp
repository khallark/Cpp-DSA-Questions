#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    if(grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    vector<vector<int>> dirs = {{0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};
    pq.push({1, 0, 0});
    dist[0][0] = 1;
    while(!pq.empty()) {
        vector<int> temp = pq.top();
        pq.pop();
        int i = temp[1], j = temp[2], distance = temp[0];
        for(auto k : dirs) {
            int I = i + k[0], J = j + k[1];
            if(I >= 0 && I < n && J >= 0 && J < n && grid[I][J] != 1) {
                if(distance + 1 < dist[I][J]) {
                    dist[I][J] = distance + 1;
                    pq.push({distance + 1, I, J});
                }
            }
        }
    }
    return dist[n - 1][n - 1] < INT_MAX ? dist[n - 1][n - 1] : -1;
}

int main() {
    vector<vector<int>> heights = {
        {0, 0, 0},
        {1, 1, 0},
        {1, 1, 0}
    };
    cout << shortestPathBinaryMatrix(heights) << endl;
    return 0;
}