#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

string bfs(vector<vector<char>> adj) {
    int n = adj.size();
    vector<int> indegree(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < adj[i].size(); j++) {
            indegree[adj[i][j] - 97]++;
        }
    }
    queue<char> q;
    string ans;
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            q.push(i + 97);
        }
    }
    while(!q.empty()) {
        char temp = q.front();
        q.pop();
        ans += temp;
        for(auto i : adj[temp - 97]) {
            indegree[i - 97] = indegree[i - 97] > 0 ? indegree[i - 97] - 1 : indegree[i - 97];
            if(indegree[i - 97] == 0) {
                q.push(i);
            }
        }
    }
    return ans;
}

string findOrder(string dict[], int N, int K) {
    if(N == 1) return dict[0];
    vector<vector<char>> edges;
    for(int i = 1; i < N; i++) {
        int len = min(dict[i - 1].length(), dict[i].length());
        int a = 0;
        while(a < len && dict[i - 1][a] == dict[i][a]) a++;
        if(a < len) edges.push_back({dict[i - 1][a], dict[i][a]});
    }
    vector<vector<char>> adj(K);
    for(auto i : edges) {
        adj[i[0] - 97].push_back(i[1]);
    }
    return bfs(adj);
}

int main() {
    string words[] = {"abca","abcd","baa","cab","cad"};
    cout << findOrder(words, 5, 4) << endl;
    return 0;
}