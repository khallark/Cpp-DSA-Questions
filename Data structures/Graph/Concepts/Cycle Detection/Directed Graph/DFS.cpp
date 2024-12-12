#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

bool dfs(vector<int> adj[], unordered_map<int, bool>& visited, unordered_map<int, bool>& call_exists, int current_node) {
    visited[current_node] = true;
    call_exists[current_node] = true;
    bool cycle = false;
    int i = 0;
    while(!cycle && i < adj[current_node].size()){
        if(!visited[adj[current_node][i]]) {
            cycle = dfs(adj, visited, call_exists, adj[current_node][i]);
            i++;
        }
        else if(call_exists[adj[current_node][i]]) {
            return true;
        }
        else {
            i++;
        }
    }
    call_exists[current_node] = false;
    return cycle;
}

bool isCycle(int V, vector<int> adj[]) {
    unordered_map<int, bool> visited;
    unordered_map<int, bool> call_exists;
    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            if(dfs(adj, visited, call_exists, i)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    vector<int> adj[] = {{}, {0, 2}, {3}, {0}, {6}, {}, {5}, {8, 9}, {10}, {8}, {}};
    cout << isCycle(11, adj);
    return 0;
}