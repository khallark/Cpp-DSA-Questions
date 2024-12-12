#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std; 

bool bfs(vector<int> adj[], unordered_map<int, int> indegree, int n) {
    queue<int> q;
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int temp = q.front();
        q.pop();
        count++;
        for(auto i : adj[temp]) {
            indegree[i] = indegree[i] > 0 ? indegree[i] - 1 : indegree[i];
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
    }
    return count != n;
}

bool topo_sort_kahn_algo(vector<int> adj[], int n) {
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
    vector<int> adj[] = {{0, 1}, {1, 2},{2, 3}, {3, 4}, {4, 2}};
    cout << topo_sort_kahn_algo(adj, 5);
    return 0;
}