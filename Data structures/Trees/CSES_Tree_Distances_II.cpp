#include <iostream>
#include <vector>
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
#define Vin(v) for(auto& i : v)
#define Vout(v) for(auto i : v)
using namespace std;

vector<vector<ll>> tree;
vector<ll> distSum, subtreeSize;
ll n;

void dfs1(ll node, ll parent) {
    subtreeSize[node] = 1;
    distSum[node] = 0;
    
    for (ll child : tree[node]) {
        if (child == parent) continue;
        dfs1(child, node);
        distSum[node] += distSum[child] + subtreeSize[child];
        subtreeSize[node] += subtreeSize[child];
    }
}

void dfs2(ll node, ll parent) {
    if (parent != -1) {
        distSum[node] = distSum[parent] + n - 2 * subtreeSize[node];
    }
    
    for (ll child : tree[node]) {
        if (child == parent) continue;
        dfs2(child, node);
    }
}

int main() {
    cin >> n;
    tree.resize(n + 1);
    distSum.resize(n + 1);
    subtreeSize.resize(n + 1);
    
    for (ll i = 0; i < n - 1; ++i) {
        ll u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    // Step 1: Calculate distance sums from node 1
    dfs1(1, -1);
    
    // Step 2: Propagate distance sums to all other nodes
    dfs2(1, -1);
    
    // Step 3: Output the result for each node
    for (ll i = 1; i <= n; ++i) {
        cout << distSum[i] << " ";
    }
    cout << endl;
    return 0;
}
