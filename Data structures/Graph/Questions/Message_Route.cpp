#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, m, a, b;
vector<vector<int>> adj;
vector<int> parent;
vector<int> path;
bool vis[100001];

bool bfs(int node) {
    queue<int> q;
    q.push(node);
    vis[node] = true;
    while(!q.empty()) {
        int temp = q.front();
        q.pop();
        if(temp == n) {
            int tempNode = n;
            while(tempNode != 1) {
                path.push_back(tempNode);
                tempNode = parent[tempNode];
            }
            path.push_back(1);
            reverse(path.begin(), path.end());
            return true;
        }
        for(auto i : adj[temp]) {
            if(!vis[i]) {
                vis[i] = true;
                parent[i] = temp;
                q.push(i);
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    adj = vector<vector<int>>(n + 1);
    parent = vector<int>(n + 1);
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if(!bfs(1)) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << path.size() << endl;
        for(auto i : path) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}