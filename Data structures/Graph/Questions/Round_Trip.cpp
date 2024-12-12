#include <iostream>
#include <queue>
#include <algorithm>
#define vvi vector<vector<int>>
#define vi vector<int>
using namespace std;
int n, m, a, b;
vvi adj;
bool vis[100001] = {0};
vi parent;
vi path;

bool bfs(int node) {
    queue<int> q;
    vis[node] = true;
    parent[node] = -1;
    q.push(node);
    while(!q.empty()) {
        int temp = q.front();
        q.pop();
        for(auto i : adj[temp]) {
            if(!vis[i]) {
                vis[i] = true;
                parent[i] = temp;
                q.push(i);
            } else if(parent[temp] != i) {
                cout << i;
                path.push_back(i);
                int current = temp;
                while(current != i) {
                    path.push_back(current);
                    // cout << current << endl;
                    current = parent[current];
                }
                path.push_back(i);
                reverse(path.begin(), path.end());
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    adj = vvi(n + 1);
    parent = vi(n + 1, -1);
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            if(bfs(i)) {
                cout << path.size() << endl;
                for(auto i : path) cout << i << " ";
                cout << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}