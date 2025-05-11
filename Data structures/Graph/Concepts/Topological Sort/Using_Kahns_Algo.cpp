#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std; 

vector<int> bfs(vector<int> adj[], unordered_map<int, int> indegree, int n) {
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
            indegree[i] = min(0, indegree[i] - 1);
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
    }
    return ans;
}

vector<int> topo_sort_kahn_algo(vector<int> adj[], int n) {
    unordered_map<int, int> indegree;
    indegree[0];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < adj[i].size(); j++) {
            indegree[adj[i][j]]++;
        }
    }

    return bfs(adj, indegree, n);
}
int main() {
    vector<int> adj[] = {{1}, {2}, {}};
    for(auto i : topo_sort_kahn_algo(adj, 3)) {
        cout << i << " ";
    }
    return 0;
}