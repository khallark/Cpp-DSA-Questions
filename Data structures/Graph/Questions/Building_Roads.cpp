#include <iostream>
#include <queue>
using namespace std;
int n, m;
vector<vector<int>> adj;
bool vis[100001];

void bfs(int node) {
    queue<int> q;
    q.push(node);
    vis[node] = true;
    while(!q.empty()) {
        int temp = q.front();
        q.pop();
        for(auto i : adj[temp]) {
            if(!vis[i]) {
                vis[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    adj = vector<vector<int>>(n + 1);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> res;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            bfs(i);
            res.push_back(i);
        }
    }
    cout << res.size() - 1 << endl;
    for(int i = 1; i < res.size(); i++) {
        cout << res[i - 1] << " " << res[i] << endl;
    }
    return 0;
}