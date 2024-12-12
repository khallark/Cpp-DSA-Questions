#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int n, m, a, b;
vector<vector<int>> adj;
vector<int> color(100001, -1);

bool bfs(int n) {
    queue<int> q;
    q.push(n);
    color[n] = 0;
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(auto i : adj[curr]) {
            if(color[i] == -1) {
                color[i] = !color[curr];
                q.push(i);
            } else if(color[i] == color[curr]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    adj = vector<vector<int>>(n + 1);
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i <= n; i++) {
        if(color[i] == -1) {
            if(!bfs(i)) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << color[i] + 1 << " ";
    }
    cout << endl;
    return 0;
}