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

    cout << maxDist << endl;
    return 0;
}