// Codechef : Cats and Trees

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

const int MAX = 18;
vector<int> parent;
vector<bool> occupied;
vector<vector<int>> table;
vector<int> ans;
int n;

int count_jumps(int node) {
    if(occupied[node]) return 0;
    int jumps = 1;
    for (int i = MAX; i >= 0; i--) {
        if(!occupied[table[i][node]]) {
            node = table[i][node];
            jumps += (1 << i);
        }
    }
    occupied[node] = true;
    return jumps;
}

int main() {
    cin >> n;
    parent.resize(n + 1);
    occupied.resize(n + 1);
    occupied[0] = true;
    ans.resize(n + 1);
    table.resize(MAX + 1, vector<int>(n + 1));
    REP(i, 1, n + 1) cin >> parent[i];

    REP(i, 1, n + 1) table[0][i] = parent[i];
    REP(i, 1, MAX + 1) { 
        REP(j, 1, n + 1) {
            table[i][j] = table[i - 1][table[i - 1][j]];
        }
    }

    REP(i, 1, n + 1) {
        int init;
        cin >> init;
        ans[i] = count_jumps(init);
    }

    REP(i, 1, n + 1) cout << ans[i] << endl;
    return 0;
}