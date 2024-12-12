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
int n, m;

int buildTree(int index, int l, int r, bool operation) {
    if(l == r) return segTree[index] = arr[l];
    int mid = l + (r - l) / 2;
    if(operation) {
        return segTree[index] = buildTree(2 * index + 1, l, mid, !operation) |
        buildTree(2 * index + 2, mid + 1, r, !operation);
    }
    return segTree[index] = buildTree(2 * index + 1, l, mid, !operation) ^
    buildTree(2 * index + 2, mid + 1, r, !operation);
}

int updateQuery(int index, int point, int val, int l, int r, bool operation) {
    if (l == r) {
        arr[l] = val;
        return segTree[index] = val;
    }
    int mid = l + (r - l) / 2;
    if (point <= mid) {
        if (operation) {
            return segTree[index] = updateQuery(2 * index + 1, point, val, l, mid, !operation) | segTree[2 * index + 2];
        }
        return segTree[index] = updateQuery(2 * index + 1, point, val, l, mid, !operation) ^ segTree[2 * index + 2];
    } else {
        if (operation) {
            return segTree[index] = segTree[2 * index + 1] | updateQuery(2 * index + 2, point, val, mid + 1, r, !operation);
        }
        return segTree[index] = segTree[2 * index + 1] ^ updateQuery(2 * index + 2, point, val, mid + 1, r, !operation);
    }
}

int main() {
    cin >> n >> m;
    int size = pow(2, n);
    arr.resize(size);
    segTree.assign(4 * size, 0);
    for(auto& i : arr) cin >> i;
    buildTree(0, 0, size - 1, n & 1);
    vector<int> ans(m);
    for(auto& i : ans) {
        int p, b;
        cin >> p >> b;
        updateQuery(0, p - 1, b, 0, size - 1, n & 1);
        i = segTree[0];
    }
    for(auto i : ans) cout << i << endl;
    return 0;
}