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

vector<int> arr;
vector<int> segTree;


int buildTree(int i, int l, int r) {
    if(l == r) return segTree[i] = arr[l];
    int mid = l + (r - l) / 2;
    return segTree[i] = buildTree(2 * i + 1, l, mid) + buildTree(2 * i + 2, mid + 1, r);
}

int sumQuery(int i, int ql, int qr, int cl, int cr) {
    if(cr < ql || cl > qr) return 0;
    if(cl >= ql && cr <= qr) return segTree[i];
    int cmid = cl + (cr - cl) / 2;
    return sumQuery(2 * i + 1, ql, qr, cl, cmid) + sumQuery(2 * i + 2, ql, qr, cmid + 1, cr);
}

int main() {
    int n, q;
    cin >> n >> q;
    arr.resize(n);
    segTree.resize(4 * n);
    Vin(arr) cin >> i;
    buildTree(0, 0, n - 1); // O(n)
    vector<int> ans(q);
    Vin(ans) {
        int l, r;
        cin >> l >> r;
        i = sumQuery(0, l, r, 0, n - 1); // O(log n)
    }
    Vout(ans) cout << i << " ";
    cout << endl;
    return 0;
}
