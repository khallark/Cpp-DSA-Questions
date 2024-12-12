#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

void dfs(vector<vector<int>> &adj, vector<int> &ans, unordered_map<int, bool> &ans_done, vector<int> &time, vector<int> &low, vector<bool> &visited, vector<int> &parent, int &t, int node) {
    time[node] = low[node] = t++;
    visited[node] = true;
    int children = 0; // Modified
    
    for(auto n : adj[node]) {
        if(!visited[n]) {
            parent[n] = node;
            children++; // Modified
            dfs(adj, ans, ans_done, time, low, visited, parent, t, n);


            low[node] = min(low[node], low[n]);


            if(parent[node] != -1 && time[node] <= low[n]) { // Condition Modified
                if(!ans_done[node]) { // Modified
                    ans.push_back(node);
                    ans_done[node] = true;
                }
            }
        }

        else if(parent[node] != n) {
            low[node] = min(low[node], time[n]); // Modified
        }
    }


    if(parent[node] == -1 && children > 1) { //
        if(!ans_done[node]) {                //
            ans.push_back(node);             // Modified
            ans_done[node] = true;           //
        }                                    //
    }                                        //
}

vector<int> articulation_points(vector<vector<int>> adj) {
    vector<int> time(adj.size(), 0);
    vector<int> low(adj.size(), 0);
    vector<bool> visited(adj.size(), false);
    vector<int> parent(adj.size(), -1);
    int t = 0;
    unordered_map<int, bool> articulation_points_done;
    vector<int> articulation_points;
    dfs(adj, articulation_points, articulation_points_done, time, low, visited, parent, t, 0);
    return articulation_points;
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

    vector<int> v = articulation_points(adj);
    for(int i = 0; i < v.size(); i++) {
        if(i < v.size() - 1) cout << v[i] << ", ";
        else cout << v[i] << endl;
    }

    return 0;
}