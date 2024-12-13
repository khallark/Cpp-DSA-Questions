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

const int MAX = 17; // for 1 <= n <= 10⁵
vector<vector<int>> table;
vector<int> parent;
vector<int> ans;
int n, m;

void PreProcess() {
    REP(i, 1, n + 1) table[0][i] = parent[i]; // First Row

    REP(i, 1, MAX + 1) {
        REP(j, 1, n + 1) {
            table[i][j] = table[i - 1][table[i - 1][j]];
        }
    }
}

int getKthParent(int a, int k) {
    REP(i, 0, MAX + 1) {
        int mask = (1 << i);
        if((k & mask) > 0) {
            a = table[i][a];
        }
    }
    return a;
}

int main() {
    cin >> n >> m;
    table.resize(MAX + 1, vector<int>(n + 1));
    parent.resize(n + 1);
    ans.resize(m);
    REP(i, 0, n) cin >> parent[i + 1];
    PreProcess();
    for(auto& i : ans) {
        int a, k;
        cin >> a >> k;
        i = getKthParent(a, k);
    }
    for(auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}

/*

27 9
0 1 1 2 10 11 9 6 3 1 2 8 9 13 3 17 2 17 22 13 14 6 13 20 20 13 8
21 3
22 1
12 5
25 140
18 3
26 4
8 3000
10 1
9 1

*/