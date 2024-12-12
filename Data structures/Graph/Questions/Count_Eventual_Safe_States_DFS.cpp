#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<vector<int>>& graph, vector<int>& dp, vector<bool>& callExists, int node) {
    if(graph[node].empty()) return true;
    if(dp[node] != -1) return dp[node];
    int isSafe = true;
    callExists[node] = true;
    for(auto i : graph[node]) {
        if(!callExists[i]) isSafe = dfs(graph, dp, callExists, i);
        else isSafe = false;
        if(isSafe == false) break;
    }
    callExists[node] = false;
    return dp[node] = isSafe;
}
vector<int> eventualSafeNodes_DFS(vector<vector<int>>& graph) {
    ios::sync_with_stdio(0);
    int n = graph.size();
    vector<int> dp(n, -1);
    vector<bool> callExists(n);
    for(int i = 0; i < n; i++) if(graph[i].empty()) dp[i] = true;
    for(int i = 0; i < n; i++) {
        callExists[i] = true;
        dfs(graph, dp, callExists, i);
        callExists[i] = false;
    }
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        if(dp[i]) ans.push_back(i);
    }
    return ans;
}

int main() {
    vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}};
    for(auto i : eventualSafeNodes_DFS(graph)) {
        cout << i << " ";
    }
    return 0;
}