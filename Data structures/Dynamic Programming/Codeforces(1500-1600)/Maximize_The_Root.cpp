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
using namespace std;

int t, n;
vector<int> val;
vector<vector<int>> tree;

int f(int node) {
    if(tree[node].size() == 0) {
        return val[node];
    }
    int mini = INT_MAX;
    for(auto child : tree[node]) {
        mini = min(mini, f(child));
    }
    if(node == 1) return mini + val[node];
    if(mini <= val[node]) return mini;
    return (val[node] + mini) / 2;
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        val = vector<int>(n + 1);
        tree = vector<vector<int>>(n + 1, vector<int>());
        for(int i = 1; i <= n; i++) cin >> val[i];
        for(int i = 2; i <= n; i++) {
            int parent;
            cin >> parent;
            tree[parent].push_back(i);
        }
        cout << f(1) << endl;
    }    
    return 0;
}