#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> reverse_graph(vector<vector<int>> adj) {
    vector<vector<int>> ans_adj(adj.size());

    for(int i = 0; i < adj.size();  i++) {
        for(auto j : adj[i]) {
            ans_adj[j].push_back(i);
        }
    }

    return ans_adj;
}

int main() {
    vector<vector<int>> adj = {
        {1},
        {2, 3, 4},
        {5},
        {},
        {1, 5},
        {2, 7},
        {7, 9},
        {10},
        {6},
        {8},
        {11},
        {9}
    };

    vector<vector<int>> reversed_adj = reverse_graph(adj);

    for(int i = 0; i < reversed_adj.size(); i++) {
        cout << i << ": ";
        for(int j = 0; j < reversed_adj[i].size(); j++) {
            if(j < reversed_adj[i].size() - 1) cout << reversed_adj[i][j] << ", ";
            else cout << reversed_adj[i][j];
        }
        cout << endl;
    }

    return 0;
}