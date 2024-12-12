#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool dfs(vector<int> adjMat[], unordered_map<int, bool>& visited, unordered_map<int, int>& parent, int node, int parent_node) {
    visited[node] = true;
    parent[node] = parent_node;
    bool cycle = false;
    int i = 0;
    while(!cycle && i < adjMat[node].size()) {
        if(!visited[adjMat[node][i]]) {
            cycle = dfs(adjMat, visited, parent, adjMat[node][i], node);
            i++;
        }
        else if(parent[node] != adjMat[node][i])
            return true;
        else 
            i++;
    }
    return cycle;
}

bool isCycle(int V, vector<int> adj[]) {
    unordered_map<int, int> parent;
    unordered_map<int, bool> visited;
    for(int i = 0; i < V; i++) { // special loop for handling graphs with broken components.
        if(!visited[i]) {
            if(dfs(adj, visited, parent, i, -1)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    vector<int> adj[] = {{1}, {0}, {3, 5}, {2}, {8, 9}, {2}, {7, 8, 9}, {6}, {4, 6}, {4, 6}};
    cout << isCycle(9, adj);
    return 0;
}