#include <iostream>
#include <queue>
using namespace std;

void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
    vector<vector<int>> moves = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
    int colLen = grid.size();
    int rowLen = grid[0].size();
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = true;
    while(!q.empty()) {
        pair<int, int> node = q.front();
        q.pop();
        int i = node.first;
        int j = node.second;
        for(auto move : moves) {
            int new_i = i + move[0];
            int new_j = j + move[1];

            if(new_i >= 0 && new_j >= 0 && new_i < colLen && new_j < rowLen && grid[new_i][new_j] != '0' && visited[new_i][new_j] == false) {
                visited[new_i][new_j] = true;
                q.push({new_i, new_j});
            }
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    int ans = 0;
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[i].size(); j++) {
            if(grid[i][j] != '0' && !visited[i][j]) {
                bfs(grid, visited, i, j);
                ans++;
            }
        }
    }
    return ans;
}
int main() {
    vector<vector<char>> islands = {
        {'0', '0', '0', '0', '0', '0', '0', '0', '1'},
        {'0', '0', '1', '1', '1', '1', '1', '0', '0'},
        {'0', '1', '0', '0', '0', '0', '0', '1', '0'},
        {'0', '1', '0', '1', '1', '1', '0', '1', '0'},
        {'0', '1', '0', '1', '1', '1', '0', '1', '0'},
        {'0', '1', '0', '1', '1', '1', '0', '1', '0'},
        {'0', '1', '0', '0', '0', '0', '0', '1', '0'},
        {'0', '0', '1', '1', '1', '1', '1', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0', '0'},
        {'1', '1', '0', '1', '1', '1', '1', '1', '1'},
    };
    cout << numIslands(islands) << endl;
    return 0;
}