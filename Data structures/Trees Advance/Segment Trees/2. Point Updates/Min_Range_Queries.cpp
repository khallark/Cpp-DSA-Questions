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

vector<int> arr;
vector<int> segTree;


int buildTree(int i, int l, int r) {
    if(l == r) return segTree[i] = arr[l];
    int mid = l + (r - l) / 2;
    return segTree[i] = min(buildTree(2 * i + 1, l, mid), buildTree(2 * i + 2, mid + 1, r));
}

int minQuery(int i, int ql, int qr, int cl, int cr) {
    if(cr < ql || cl > qr) return INT_MAX;
    if(cl >= ql && cr <= qr) return segTree[i];
    int cmid = cl + (cr - cl) / 2;
    return min(minQuery(2 * i + 1, ql, qr, cl, cmid), minQuery(2 * i + 2, ql, qr, cmid + 1, cr));
}

int updateQuery(int i, int point, int val, int l, int r) {
    if(l == r) return segTree[i] = l == point ? val : arr[l];
    int mid = l + (r - l) / 2;
    if(point <= mid) {
        segTree[i] = min(updateQuery(2 * i + 1, point, val, l, mid), segTree[2 * i + 2]);
    } else {
        segTree[i] = min(segTree[2 * i + 1], updateQuery(2 * i + 2, point, val, mid + 1, r));
    }
    return segTree[i];
}

int main() {
    int n, q;
    cin >> n >> q;
    arr.resize(n);
    segTree.resize(4 * n);
    for(auto& i : arr) cin >> i;
    buildTree(0, 0, n - 1); // O(n)
    vector<int> ans;
    REP(i, 0, q) {
        int mode, val, point, l, r;
        cin >> mode;
        if(mode) {
            cin >> point >> val;
            updateQuery(0, point, val, 0, n - 1);
        } else {
            cin >> l >> r;
            ans.push_back(minQuery(0, l, r, 0, n - 1)); // O(log n)
        }
    }
    for(auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}
/*
8 5
41 62 98 23 57 89 112 220
0 1 4
1 4 12
0 2 6
1 7 1
0 0 7
*/