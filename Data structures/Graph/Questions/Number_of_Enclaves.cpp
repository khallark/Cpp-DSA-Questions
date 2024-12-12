#include <iostream>
#include <queue>
using namespace std;

int numEnclaves(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dirs = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
    queue<vector<int>> q;
    for(int i = 0; i < m; i++) {
        if(grid[i][0]) grid[i][0] = 0, q.push({i, 0});
        if(grid[i][n - 1]) grid[i][n - 1] = 0, q.push({i, n - 1});
    }
    for(int i = 0; i < n; i++) {
        if(grid[0][i]) grid[0][i] = 0, q.push({0, i});
        if(grid[m - 1][i]) grid[m - 1][i] = 0, q.push({m - 1, i});
    }
    while(!q.empty()) {
        int i = q.front()[0], j = q.front()[1];
        q.pop();
        for(auto k : dirs) {
            int I = i + k[0], J = j + k[1];
            if(I >= 0 && I < m && J >= 0 && J < n && grid[I][J])
                grid[I][J] = 0, q.push({I, J});
        }
    }
    int ans = 0;
    for(auto i : grid) for(auto j : i) ans += j;
    return ans;
}

int main() {
    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };
    cout << numEnclaves(grid);
    return 0;
}