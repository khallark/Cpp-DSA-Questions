#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &adj, vector<bool> &visited, int node) {
    visited[node] = true;
    for(auto i : adj[node]) {
        if(!visited[i]) {
            dfs(adj, visited, i);
        }
    }
}

int numberOfComponents(vector<vector<int>> &connections, int n) {
    // Make adjecency list
    vector<vector<int>> adj(n);
    for(auto i : connections) {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
    // Find out number of components using DFS
    vector<bool> visited(n, false);
    int num_components = 0;
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            num_components++;
            dfs(adj, visited, i);
        }
    }
    return num_components;
}

int findParent(int node, vector<int> &parent) {
    if(parent[node] == node) {
        return node;
    }
    return parent[node] = findParent(parent[node], parent);
}

void union_set(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findParent(u, parent);
    v = findParent(v, parent);
    if(rank[u] > rank[v]) {
        parent[v] = u;
    }
    else if(rank[v] > rank[u]) {
        parent[u] = v;
    }
    else {
        parent[v] = u;
        rank[u]++;
    }
}

int extraEdges(vector<vector<int>> &connections, int n) {
    vector<int> parent(n);
    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }
    vector<int> rank(n, 0);
    int extra_edges = 0;
    for(int i = 0; i < connections.size(); i++) {
        int u = findParent(connections[i][0], parent);
        int v = findParent(connections[i][1], parent);
        if(u != v) {
            union_set(u, v, parent, rank);
        }
        else extra_edges++;
    }
    return extra_edges;
}

int makeConnected(int n, vector<vector<int>>& connections) {
    int ee = extraEdges(connections, n);
    int nc = numberOfComponents(connections, n);
    cout << "ee = " << ee << endl;
    cout << "nc = " << nc << endl;
    return ee >= nc - 1 ? nc - 1 : -1;
}