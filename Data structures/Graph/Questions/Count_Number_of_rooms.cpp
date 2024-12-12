#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
    visited[i][j] = true;
    int row[] = {0, -1, 0, 1};
    int col[] = {-1, 0, 1, 0};
    for(int k = 0; k < 4; k++) {
        int I = i + row[k];
        int J = j + col[k];
        if(I >= 0 && I < grid.size() && J >= 0 && J < grid[0].size() && grid[I][J] == '.' && !visited[I][J]) {
            dfs(grid, visited, I, J);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for(auto& i : grid) {
        for(auto& j : i) {
            cin >> j;
        }
    }
    vector<vector<bool>> visited(n, vector<bool>(m));
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == '.' && !visited[i][j]) {
                dfs(grid, visited, i, j);
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}