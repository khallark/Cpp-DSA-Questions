#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>

#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int, int>
#define pll pair<ll, ll>
#define REP(i, x, y) for(int i = x; i < y; i++)
#define REPR(i, x, y) for(int i = x; i >= y; i--)
using namespace std;

const int MAX = 17;
vector<int> depth;
vector<int> parent;
vector<vector<int>> table;
vector<vector<int>> tree;
int n, m, max_depth = -1;

int LCA(int u, int v) {
    int upper = depth[u] < depth[v] ? u : v;
    int lower = upper == u ? v : u;
    int depth_diff = depth[lower] - depth[upper];

    // bringing u and v at the same depth
    REP(i, 0, MAX + 1) {
        if(((1 << i) & depth_diff) > 0) {
            lower = table[i][lower];
        }
    }
    u = upper, v = lower;


    // finding the LCA
    if(u == v) return u;
    REPR(j, log2(max_depth), 0) {
        if(table[j][u] != table[j][v]) {
            u = table[j][u];
            v = table[j][v];
        }
    }

    return table[0][u];
}

int main() { // O(m * log n)
    // inputs
    cin >> n >> m;
    depth.resize(n + 1);
    parent.resize(n + 1);
    tree.resize(n + 1, vector<int>());
    table.resize(MAX + 1, vector<int>(n + 1));
    REP(i, 1, n + 1) {
        int freq;
        cin >> freq;
        REP(j, 0, freq) {
            int node;
            cin >> node;
            tree[i].push_back(node);
            tree[node].push_back(i);
        }
    }

    // get the depth of all node, and the maximum depth of the tree
    queue<pi> q;
    vector<bool> visited(n + 1);
    q.push({1, 0});
    visited[1] = true;
    while(!q.empty()) { // O(n)
        auto [node, lvl] = q.front();
        q.pop();
        depth[node] = lvl;
        max_depth = max(max_depth, lvl);
        for(auto child : tree[node]) {
            if(!visited[child]) {
                parent[child] = node;
                visited[child] = true;
                q.push({child, lvl + 1});
            }
        }
    }

    // preprocessing the binary lifting table O(n)
    REP(i, 1, n + 1) table[0][i] = parent[i];
    REP(i, 1, MAX + 1) { 
        REP(j, 1, n + 1) {
            table[i][j] = table[i - 1][table[i - 1][j]];
        }
    }

    // queries
    vector<int> ans(m);
    for(auto& i : ans) { // O(m * log n)
        int u, v;
        cin >> u >> v;
        i = LCA(u, v); // O(log n)
    }

    // output
    cout << endl;
    for(auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}
/*

27 8

3 3 10 2
3 17 4 11
2 15 9
0
0
2 8 22
0
2 12 27
2 7 13
1 5
1 6
0
4 23 20 14 26
1 21
0
0
2 16 18
0
0
2 25 24
0
1 19
0
0
0
0
0

23 26
21 19
21 3
16 12
27 22
5 1
7 21
18 2

*/