#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

void topo_sort_kahn_algo(vector<vector<int>> adj, vector<int> &parent, int n) {
    unordered_map<int, int> indegree;
    indegree[0];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < adj[i].size(); j++) {
            indegree[adj[i][j]]++;
        }
    }

    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int temp = q.front();
        q.pop();
        for(auto i : adj[temp]) {
            indegree[i] = indegree[i] > 0 ? indegree[i] - 1 : indegree[i];
            if(indegree[i] == 0) {
                parent[i] = parent[i] == -1 ? temp : parent[i];
                q.push(i);
            }
        }
    }
}

vector<int> minimumTime(int n, vector<vector<int>> &edges, int m) {
    vector<vector<int>> adj(n);
    for(auto i : edges) {
        adj[i[0] - 1].push_back(i[1] - 1);
    }
    vector<int> parent(n, -1);
    topo_sort_kahn_algo(adj, parent, n);

    vector<int> ans(n);
    for(int i = 0; i < n; i++) {
        int count = 0;
        int node = i;
        while(node != -1) {
            node = parent[node];
            count++;
        }
        ans[i] = count;
    }

    return ans;
}

int main() {
    vector<vector<int>> edges = {{1,2},{2,3},{2,4},{2,5},{3,6},{4,6},{5,7}};
    int N = 7, E = 7;

    vector<int> time = minimumTime(N, edges, E);
    for(auto i : time) {
        cout << i << " ";
    }
    return 0;
}