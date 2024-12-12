#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;


bool kahn_algo(vector<vector<int>>& adj, vector<bool> &visited, int n) {
    unordered_map<int, int> indegree;
    indegree[0];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < adj[i].size(); j++) {
            indegree[adj[i][j]]++;
        }
    }

    queue<int> q;
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(!visited[i] && indegree[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int temp = q.front();
        q.pop();
        count++;
        for(auto i : adj[temp]) {
            visited[i] = true;
            indegree[i] = indegree[i] > 0 ? indegree[i] - 1 : indegree[i];
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
    }
    return count != n;
}


bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
    vector<vector<int>> adj(N);
    for(auto i : prerequisites) {
        adj[i.first].push_back(i.second);
    }
    
    vector<bool> visited(N, false);
    for(int i = 0; i < N; i++) {
        if(!visited[i]) {
            if(kahn_algo(adj, visited, N) == true) {
                return false;
            }
        }
    }

    return true;
}


int main() {
    vector<pair<int, int>> edges = {{0, 1}, {1, 2}, {2, 1}};
    int N = 4;
    int P = edges.size();
    cout << isPossible(N, P, edges);
    return 0;
}