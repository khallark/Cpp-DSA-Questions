#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void tarjans_dfs_solve(vector<vector<int>> adj, vector<pair<int, int>> &bridges, int &timer, vector<int> &time, vector<int> &low, vector<int> &parent, vector<bool> &visited, int node, int parent_node) {

    visited[node] = true;
    time[node] = timer;
    low[node] = timer;
    parent[node] = parent_node;
    timer++;

    for(auto neighbour : adj[node]) {
        if(!visited[neighbour]) {
            tarjans_dfs_solve(adj, bridges, timer, time, low, parent, visited, neighbour, node);

            low[node] = min(low[node], low[neighbour]);

            if(time[node] < low[neighbour]) {
                bridges.push_back(make_pair(node, neighbour));
            }
        }
        else if(parent[node] != neighbour) {
            low[node] = min(low[node], low[neighbour]);
        }
    }
}

vector<pair<int, int>> bridges_in_graph(vector<vector<int>> adj) {
    vector<pair<int, int>> bridges;

    vector<int> time(adj.size(), -1);
    vector<int> low(adj.size(), -1);
    vector<int> parent(adj.size(), -1);
    vector<bool> visited(adj.size(), false);
    int timer = 0;

    tarjans_dfs_solve(adj, bridges, timer, time, low, parent, visited, 0, -1);

    reverse(bridges.begin(), bridges.end());
    return bridges;
}

int main() {
    vector<vector<int>> adj = {
        {1},
        {0, 2, 3},
        {1, 3},
        {1, 2, 4},
        {3, 6, 8},
        {7},
        {4, 7},
        {5, 6, 8},
        {4, 7, 9},
        {8, 10, 11},
        {9},
        {9, 12, 13, 14},
        {11, 13, 14},
        {11, 12},
        {11, 12}
    };

    cout << "Bridges {" << endl;
    vector<pair<int, int>> v = bridges_in_graph(adj);
    for(int i = 0; i < v.size(); i++) {
        if(i < v.size() - 1) cout << "   " << v[i].first << "-+-" << v[i].second << "," << endl;
        else cout << "   " << v[i].first << "-+-" << v[i].second << endl;
    }
    cout << "}";

    return 0;
}