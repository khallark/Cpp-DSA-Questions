#include <iostream>
#include <vector>
using namespace std;

pair<int, int> findParent(pair<int, int> n, vector<vector<pair<int, int>>>& parent) {
    if(parent[n.first][n.second] == n) {
        return n;
    }
    return parent[n.first][n.second] = findParent(parent[n.first][n.second], parent);
}

void union_(pair<int, int> u, pair<int, int> v, vector<vector<int>>& rank, vector<vector<pair<int, int>>>& parent) {
    u = findParent(u, parent);
    v = findParent(v, parent);
    if(u == v) return;
    if(rank[u.first][u.second] == rank[v.first][v.second])
        parent[v.first][v.second] = u,
        rank[u.first][u.second]++;
    else if(rank[u.first][u.second] > rank[v.first][v.second])
        parent[v.first][v.second] = u;
    else
        parent[u.first][u.second] = v;
}

vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
    vector<vector<bool>> water(n, vector<bool>(m));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            parent[i][j] = {i, j};
        }
    }
    vector<vector<int>> rank(n, vector<int>(m));
    vector<int> ans;
    vector<int> row = {0, 1, 0, -1};
    vector<int> col = {-1, 0, 1, 0};
    for(auto query : operators) {
        int i = query[0], j = query[1];
        if(water[i][j] == 0) {
            water[i][j] = 1;
            for(int k = 0; k < 4; k++) {
                int I = i + row[k], J = j + col[k];
                if(I >= 0 && I < n && J >= 0 && J < m) {
                    if(water[I][J] == 1) {
                        union_({i, j}, {I, J}, rank, parent);
                    }
                }
            }
        }
        int num = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(water[i][j] == 1 &&
                findParent({i, j}, parent) == make_pair(i, j))
                    num++;
            }
        }
        ans.push_back(num);
    }
    return ans;
}

int main() {
    vector<vector<int>> queries = {{1,1},{0,1},{3,3},{3,4}};
    int n = 4, m = 4;
    for(auto i : numOfIslands(n, m, queries)) {
        cout << i << " ";
    }
    return 0;
}