#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> Weighted_edges(vector<vector<pair<int, int>>>& adj) {
    vector<vector<int>> ans;
    for(int i = 0; i < adj.size(); i++) {
        for(auto j : adj[i]) {
            ans.push_back({i, j.first, j.second});
        }
    }
    return ans;
}
int main() {
    vector<vector<pair<int, int>>> adj = {
        {{1, 7}, {2, 1}, {3, 2}},
        {{0, 7}, {2, 3}, {3, 5}, {4, 1}},
        {{0, 1}, {1, 3}},
        {{0, 2}, {1, 5}, {4, 7}},
        {{1, 1}, {3, 7}}
    };

    int n = adj.size();

    int source_node = 0;

    for(auto i : Weighted_edges(adj)) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}