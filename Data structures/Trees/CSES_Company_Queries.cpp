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

int Xor[200001];
int nodes[200001];
vector<int> boss;
vector<vector<int>> tree;
int n, q;

void dfs(int node, int parent, int XOR) {
    Xor[node] = XOR;
    nodes[XOR] = node;
    for(auto child : tree[node]) {
        if(child != parent) dfs(child, node, XOR ^ child);
    }
}

int main() {
    cin >> n >> q;
    boss.resize(n + 1);
    for(int i = 2; i <= n; i++) cin >> boss[i];
    tree.resize(n + 1);
    for(int i = 2; i <= n; i++) {
        tree[i].push_back(boss[i]);
        tree[boss[i]].push_back(i);
    }
    dfs(1, -1, 1);
    vector<int> bosses;
    for(int i = 0; i < q; i++) {
        int x, k;
        cin >> x >> k;
        int ans = Xor[x];
        for(int i = k; i > 0; i--) {
            ans = ans ^ nodes[ans];
            if(ans == 0) {
                ans = -1;
                break;
            }
        }
        if(ans == -1) bosses.push_back(ans);
        else bosses.push_back(nodes[ans]);
    }
    for(auto i : bosses) cout << i << endl;
    return 0;
}