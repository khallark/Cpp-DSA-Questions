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

int main() {
    int n, q;
    cin >> n >> q;
    arr.resize(n);
    segTree.resize(4 * n);
    for(auto& i : arr) cin >> i;
    buildTree(0, 0, n - 1); // O(n)
    vector<int> ans(q);
    for(auto& i : ans) {
        int l, r;
        cin >> l >> r;
        i = minQuery(0, l, r, 0, n - 1); // O(log n)
    }
    for(auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}