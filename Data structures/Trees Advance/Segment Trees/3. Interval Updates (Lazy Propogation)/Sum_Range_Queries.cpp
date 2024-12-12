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
vector<int> lazyTree;


int buildTree(int i, int l, int r) {
    if(l == r) return segTree[i] = arr[l];
    int mid = l + (r - l) / 2;
    return segTree[i] = buildTree(2 * i + 1, l, mid) + buildTree(2 * i + 2, mid + 1, r);
}

int sumQuery(int i, int ql, int qr, int cl, int cr) {
    if(lazyTree[i] != 0) {
        segTree[i] += (cr - cl + 1) * lazyTree[i];
        if(cl != cr) {
            lazyTree[2 * i + 1] += lazyTree[i];
            lazyTree[2 * i + 2] += lazyTree[i];
        }
        lazyTree[i] = 0;
    }

    if(cr < ql || cl > qr) return 0;
    if(cl >= ql && cr <= qr) return segTree[i];
    int cmid = cl + (cr - cl) / 2;
    return sumQuery(2 * i + 1, ql, qr, cl, cmid) + sumQuery(2 * i + 2, ql, qr, cmid + 1, cr);
}

int updateQuery(int i, int L, int R, int val, int l, int r) {
    if(lazyTree[i] != 0) {
        segTree[i] += (r - l + 1) * lazyTree[i];
        if(l != r) {
            lazyTree[2 * i + 1] += lazyTree[i];
            lazyTree[2 * i + 2] += lazyTree[i];
        }
        lazyTree[i] = 0;
    }

    if(r < L || l > R) {
        return segTree[i];
    } else if(l >= L && r <= R) {
        segTree[i] += (r - l + 1) * val;
        if(l != r) {
            lazyTree[2 * i + 1] += val;
            lazyTree[2 * i + 2] += val;
        }
        return segTree[i];
    }
    int mid = l + (r - l) / 2;
    return segTree[i] = updateQuery(2 * i + 1, L, R, val, l, mid) +
                        updateQuery(2 * i + 2, L, R, val, mid + 1, r);
}

int main() {
    int n, q;
    cin >> n >> q;
    arr.assign(n, 0);
    segTree.assign(4 * n, 0);
    lazyTree.assign(4 * n, 0);
    for(auto& i : arr) cin >> i;
    buildTree(0, 0, n - 1); // O(n)
    vector<int> ans;
    REP(i, 0, q) {
        int mode, L, R, val, l, r;
        cin >> mode;
        if(mode) {
            cin >> L >> R >> val;
            updateQuery(0, L - 1, R - 1, val, 0, n - 1); // O(log n)
        } else {
            cin >> l >> r;
            ans.push_back(sumQuery(0, l - 1, r - 1, 0, n - 1)); // O(log n)
        }
    }
    for(auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}
/*
10 8
6 1 8 14 4 7 9 10 2 20
0 2 6
1 4 7 -3
0 6 10
1 1 5 5
1 5 9 -7
0 7 10
1 1 10 4
0 1 10
*/