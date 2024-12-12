#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <limits.h>
using namespace std;


// Approach 1 - DFS (Recursion)
void solve(vector<vector<pair<int, int>>> adj, vector<int>& ans, int source, int weights_sum) {
    ans[source] = min(weights_sum, ans[source]);

    for(auto neighbours : adj[source]) {
        solve(adj, ans, neighbours.first, weights_sum + neighbours.second);
    }
} vector<int> shortest_path_dfs_recursion(vector<vector<pair<int, int>>> adj, int n, int source_node) {
    vector<int> ans(n, INT_MAX);
    solve(adj, ans, source_node, 0);
    return ans;
}


// Approach 2 - BFS (Topological Sort)
void topological_sort(vector<vector<pair<int, int>>> adj, stack<int>& s, unordered_map<int, bool>& visited, int source_node) {
    visited[source_node] = true;

    for(auto neighbours : adj[source_node]) {
        if(!visited[neighbours.first]) {
            topological_sort(adj, s, visited, neighbours.first);
        }
    }

    s.push(source_node);
}
vector<int> shortest_path_using_topological_sort(vector<vector<pair<int, int>>> adj, int n, int source_node) {
    unordered_map<int, bool> visited;
    vector<int> ans(n, INT_MAX);
    ans[source_node] = 0;
    stack<int> s;
    topological_sort(adj, s, visited, source_node);

    while(!s.empty()) {
        int node = s.top();
        s.pop();
        if(ans[node] != INT_MAX) {
            for(auto neighbours : adj[node]) {
                if(ans[node] + neighbours.second < ans[neighbours.first]) {
                    ans[neighbours.first] = ans[node] + neighbours.second;
                }
            }
        }
    }

    return ans;
}


int main() {
    vector<vector<pair<int, int>>> adj = { // Directed Acyclic Graph
        /*0->*/ {{1, 5}},
        /*1->*/ {{2, 2}, {3, 7}, {4, 4}, {5, 6}, {7, -2}},
        /*2->*/ {{3, -9}},
        /*3->*/ {{6, 2}},
        /*4->*/ {{5, 2}, {8, -5}},
        /*5->*/ {},
        /*6->*/ {{10, -2}},
        /*7->*/ {{9, 7}, {10, 20}},
        /*8->*/ {{10, 10}},
        /*9->*/ {},
        /*10->*/{},
    };

    int n = adj.size();

    int source_node = 0;

    for(auto i : shortest_path_using_topological_sort(adj, n, source_node)) {
        if(i == INT_MAX) {
            cout << "INF ";
        }
        else {
            cout << i << " ";
        }
    }
    
    return 0;
}