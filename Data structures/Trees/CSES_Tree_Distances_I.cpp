#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int, int>
#define pll pair<ll, ll>
#define REP(i, x, y) for(int i = x; i < y; i++)
#define REPR(i, x, y) for(int i =y; i >= y; i--)
#define Vin(v) for(auto& i : v)
#define Vout(v) for(auto i : v)
using namespace std;

vector<vector<int>> tree(200001);

void dfs(int node, int parent, int dist, int& maxDist, int& farthestNode) {
    if(dist > maxDist) {
        maxDist = dist;
        farthestNode = node;
    }
    for(auto child : tree[node]) {
        if(child != parent) {
            dfs(child, node, dist + 1, maxDist, farthestNode);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<bool> nodes(n + 1);
    REP(i, 0, n - 1) {
        int a, b;
        cin >> a >> b;
        nodes[b] = true;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    int maxDist = -1, farthestNodeA;
    dfs(1, -1, 0, maxDist, farthestNodeA);
    
    maxDist = -1;
    int farthestNodeB;
    dfs(farthestNodeA, -1, 0, maxDist, farthestNodeB);

    queue<pi> q;

    q.push({0, farthestNodeA});
    vector<int> distA(n + 1);
    vector<bool> visited(n + 1, false);
    visited[farthestNodeA] = true;
    while(!q.empty()) {
        auto [dist, node] = q.front();
        q.pop();
        distA[node] = dist;
        for(auto child : tree[node]) {
            if(!visited[child]) {
                visited[child] = true;
                q.push({dist + 1, child});
            }
        }
    }

    q.push({0, farthestNodeB});
    vector<int> distB(n + 1);
    visited = vector<bool>(n + 1, false);
    visited[farthestNodeB] = true;
    while(!q.empty()) {
        auto [dist, node] = q.front();
        q.pop();
        distB[node] = dist;
        for(auto child : tree[node]) {
            if(!visited[child]) {
                visited[child] = true;
                q.push({dist + 1, child});
            }
        }
    }

    REP(i, 1, n + 1) {
        cout << distA[i] << " ";
    }
    cout << endl;
    REP(i, 1, n + 1) {
        cout << distB[i] << " ";
    }
    cout << endl;
    return 0;
}