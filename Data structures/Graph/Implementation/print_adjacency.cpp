#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// given number of nodes, and number of edges, create an adjecency list
vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>>& edges) {
    sort(edges.begin(), edges.end());
    vector<vector<int>> ans(n);

    for(int i = 0; i < m; i++) {
        ans[edges[i][0]].push_back(edges[i][1]);
        ans[edges[i][1]].push_back(edges[i][0]);
    }

    return ans;
}

int main() {
    vector<vector<int>> edges = {{0,1},{0,4},{4,1},{4,3},{1,3},{1,2},{3,2}};
    int n = 5;
    int m = 7;
    vector<vector<int>> ans = printAdjacency(n, m, edges);
    for(auto i : ans) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}