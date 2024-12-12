#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void finishing_time_order(vector<vector<int>>& adj, stack<int> &s, vector<bool> &visited, int node) {
    visited[node] = true;

    for(auto neighbour : adj[node]) {
        if(!visited[neighbour]) {
            finishing_time_order(adj, s, visited, neighbour);
        }
    }

    s.push(node);
}

vector<vector<int>> reverse_graph(vector<vector<int>>& adj) {
    vector<vector<int>> new_adj(adj.size());

    for(int i = 0; i < adj.size(); i++) {
        for(auto j : adj[i]) {
            new_adj[j].push_back(i);
        }
    }

    return new_adj;
}

void dfs(vector<vector<int>>& adj, vector<bool>& visited, vector<int>& scc, int node) {
    scc.push_back(node);
    visited[node] = true;
    for(auto neighbour : adj[node]) {
        if(!visited[neighbour]) {
            dfs(adj, visited, scc, neighbour);
        }
    }
}
void kosaraju_algo(vector<vector<int>>& adj, stack<int> &s, vector<vector<int>> &scc) {
    vector<bool> visited(adj.size(), false);
    while(!s.empty()) {
        if(!visited[s.top()]) {
            vector<int> scc_;
            dfs(adj, visited, scc_, s.top());
            scc.push_back(scc_);
        }
        s.pop();
    }
}

vector<vector<int>> strongly_connected_components(vector<vector<int>>& adj) {
    // Step 1: Sorting out the nodes in order of there DFS finishing.
    stack<int> s;
    vector<bool> visited(adj.size(), false);
    for(int i = 0; i < adj.size(); i++)
        if(!visited[i]) 
            finishing_time_order(adj, s, visited, i);

    // Step 2: Make a new adjecency List with reversed connections.
    adj = reverse_graph(adj);

    // Step 3: Find out the SCC's using Kosaraju's Algorithm.
    vector<vector<int>> scc;
    kosaraju_algo(adj, s, scc);

    return scc;
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

    vector<vector<int>> scc = strongly_connected_components(adj);

    int c = 0;
    for(auto i : scc) {
        cout << "SCC_" << c++ << " = ";
        for(auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}