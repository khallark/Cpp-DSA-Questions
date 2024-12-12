#include <iostream>
#include <vector>
#include <set>
using namespace std;

pair<int, int> findParent(pair<int, int> n, vector<vector<pair<int, int>>>& parent) {
    if(parent[n.first][n.second] == n) {
        return n;
    }
    return parent[n.first][n.second] = findParent(parent[n.first][n.second], parent);
}

void union_(pair<int, int> u, pair<int, int> v, vector<vector<int>>& size,
vector<vector<pair<int, int>>>& parent) {
    u = findParent(u, parent);
    v = findParent(v, parent);
    if(u == v) return;
    if(size[u.first][u.second] == size[v.first][v.second])
        parent[v.first][v.second] = u,
        size[u.first][u.second] += size[v.first][v.second];
    else if(size[u.first][u.second] > size[v.first][v.second])
        parent[v.first][v.second] = u,
        size[u.first][u.second] += size[v.first][v.second];
    else
        parent[u.first][u.second] = v,
        size[v.first][v.second] += size[u.first][u.second];
}
int largestIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<int>> size(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            size[i][j] = grid[i][j];
        }
    }
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            parent[i][j] = {i, j};
        }
    }
    vector<int> row = {0, 1, 0, -1};
    vector<int> col = {-1, 0, 1, 0};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 0) continue;
            for(int k = 0; k < 4; k++) {
                int I = i + row[k], J = j + col[k];
                if(I >= 0 && I < n && J >= 0 && J < n && grid[I][J] == 1) {
                    union_({i, j}, {I, J}, size, parent);
                }
            }
        }
    }
    int ans = 0;
    set<pair<int, int>> s;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 1) continue;
            for(int k = 0; k < 4; k++) {
                int I = i + row[k], J = j + col[k];
                if(I >= 0 && I < n && J >= 0 && J < n && grid[I][J] == 1) {
                    s.insert(findParent({I, J}, parent));
                }
            }
            int sum = 0;
            for(auto k : s) {
                sum += size[k.first][k.second];
            }
            ans = max(ans, sum + 1);
            s.clear();
        }
    }
    return ans == 0 ? n * n : ans;
}

int main() {
    vector<vector<int>> grid = {
        {1, 0, 1},
        {0, 0, 0},
        {0, 1, 1}
    };
    cout << largestIsland(grid);
    return 0;
}