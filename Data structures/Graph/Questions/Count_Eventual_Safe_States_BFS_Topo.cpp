#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> bfs(vector<vector<int>> adj) {
    int n = adj.size();
    vector<int> indegree(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < adj[i].size(); j++) {
            indegree[adj[i][j]]++;
        }
    }
    queue<int> q;
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int temp = q.front();
        q.pop();
        ans.push_back(temp);
        for(auto i : adj[temp]) {
            indegree[i] = indegree[i] > 0 ? indegree[i] - 1 : indegree[i];
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
    }
    return ans;
}

vector<int> eventualSafeNodes_BFS(vector<vector<int>>& graph) {
    vector<vector<int>> adj(graph.size());
    for(int i = 0; i < graph.size();  i++) {
        for(auto j : graph[i]) {
            adj[j].push_back(i);
        }
    }
    vector<int> ans = bfs(adj);
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}};
    for(auto i : eventualSafeNodes_BFS(graph)) {
        cout << i << " ";
    }
    return 0;
}