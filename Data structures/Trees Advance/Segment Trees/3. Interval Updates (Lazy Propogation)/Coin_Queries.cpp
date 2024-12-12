/*
Given a binary array (say 0,1,1,0,1,0,0,1...)
2 Queries :
Seek(0) -> number of 1's in an interval (a,b).
Update(1) -> flip values in an interval (a,b).
*/

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
vector<bool> lazyTree;


int buildTree(int i, int l, int r) {
    if(l == r) return segTree[i] = arr[l];
    int mid = l + (r - l) / 2;
    return segTree[i] = buildTree(2 * i + 1, l, mid) + buildTree(2 * i + 2, mid + 1, r);
}

int sumQuery(int i, int ql, int qr, int cl, int cr) {
    if(lazyTree[i]) {
        segTree[i] = (cr - cl + 1) - segTree[i];
        if(cl != cr) {
            lazyTree[2 * i + 1] = !lazyTree[2 * i + 1];
            lazyTree[2 * i + 2] = !lazyTree[2 * i + 2];
        }
        lazyTree[i] = false;
    }

    if(cr < ql || cl > qr) return 0;
    if(cl >= ql && cr <= qr) return segTree[i];
    int cmid = cl + (cr - cl) / 2;
    return sumQuery(2 * i + 1, ql, qr, cl, cmid) + sumQuery(2 * i + 2, ql, qr, cmid + 1, cr);
}

int updateQuery(int i, int L, int R, int l, int r) {
    if(lazyTree[i]) {
        segTree[i] = (r - l + 1) - segTree[i];
        if(l != r) {
            lazyTree[2 * i + 1] = !lazyTree[2 * i + 1];
            lazyTree[2 * i + 2] = !lazyTree[2 * i + 2];
        }
        lazyTree[i] = false;
    }

    if(r < L || l > R) {
        return segTree[i];
    } else if(l >= L && r <= R) {
        segTree[i] = (r - l + 1) - segTree[i];
        if(l != r) {
            lazyTree[2 * i + 1] = !lazyTree[2 * i + 1];
            lazyTree[2 * i + 2] = !lazyTree[2 * i + 2];
        }
        return segTree[i];
    }
    int mid = l + (r - l) / 2;
    return segTree[i] = updateQuery(2 * i + 1, L, R, l, mid) +
                        updateQuery(2 * i + 2, L, R, mid + 1, r);
}

int main() {
    int n, q;
    cin >> n >> q;
    arr.assign(n, 0);
    segTree.assign(4 * n, 0);
    lazyTree.assign(4 * n, false);
    for(auto& i : arr) cin >> i;
    buildTree(0, 0, n - 1); // O(n)
    vector<int> ans;
    REP(i, 0, q) {
        int mode, L, R, l, r;
        cin >> mode;
        if(mode) {
            cin >> L >> R;
            updateQuery(0, L - 1, R - 1, 0, n - 1); // O(log n)
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
12 5
0 1 1 0 1 0 1 1 0 1 0 0
0 3 6
1 2 7
0 4 9
1 1 12
0 1 12
*/