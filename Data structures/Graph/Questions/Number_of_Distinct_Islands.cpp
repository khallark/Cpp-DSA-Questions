#include <iostream>
#include <vector>
#include <set>
using namespace std;

void dfs(vector<vector<int>>& grid, vector<vector<int>>& dirs, string& s, int i, int j) {
    grid[i][j] = 0;
    int cnt = 0;
    for(auto k : dirs) {
        int I = i + k[0], J = j + k[1];
        if(I >= 0 && I < grid.size() && J >= 0 && J < grid[0].size()
        && grid[I][J]) {
            if(cnt == 0) s += 'L';
            if(cnt == 1) s += 'U';
            if(cnt == 2) s += 'R';
            if(cnt == 3) s += 'D';
            dfs(grid, dirs, s, I, J);
        }
        cnt++;
    }
    s += '#';
}
int countDistinctIslands(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    set<string> s;
    vector<vector<int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j]) {
                string st = "";
                dfs(grid, dirs, st, i, j);
                s.insert(st);
            }
        }
    }
    return s.size();
}

int main() {
    vector<vector<int>> islands = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1}
    };
    cout << countDistinctIslands(islands);
    return 0;
}