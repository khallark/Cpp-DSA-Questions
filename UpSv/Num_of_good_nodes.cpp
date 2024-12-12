#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dfs(vector<vector<int>> &adj, vector<int>& parents, int &count, int node) {
    int size = -1;
    bool isGood = true;
    int ans = 0;
    for(auto i : adj[node]) {
        if(parents[node] != i) {
            parents[i] = node;
            int val = dfs(adj, parents, count, i);
            ans += val;
            if(size == -1) size = val;
            if(val != size) isGood = false;
        }
    }
    count += isGood;
    return ans + 1;
}
int countGoodNodes(vector<vector<int>>& edges) {
    vector<vector<int>> adj(edges.size() + 1);
    vector<int> parents(edges.size() + 1, -1);
    for(auto i : edges) {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
    int count = 0;
    dfs(adj, parents, count, 0);
    return count;
}
int main() {
    vector<vector<int>> edges = {{0,1},{1,2},{1,3},{1,4},{0,5},{5,6},{6,7},{7,8},{0,9},{9,10},{9,12},{10,11}};
    cout << countGoodNodes(edges) << endl;
    return 0;
}