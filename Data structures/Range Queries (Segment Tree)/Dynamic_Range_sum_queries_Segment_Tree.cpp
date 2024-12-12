#include <iostream>
#include <vector>
#define ll long long
using namespace std;
int n, q;
vector<ll> nums;
vector<ll> segTree;

// O(2 * n)
ll buildSegTree(int i, int l, int r) {
    if(l == r) return segTree[i] = nums[l];
    int mid = l + (r - l) / 2;
    return segTree[i] = buildSegTree(2 * i + 1, l, mid)
                      + buildSegTree(2 * i + 2, mid + 1, r);
}

// O(log N)
ll updateQuery(int i, int k, ll u, int l, int r) {
    if(l == r) {
        if(l == k) return segTree[i] = u;
        return segTree[i];
    }
    int mid = l + (r - l) / 2;
    if(k <= mid) {
        return segTree[i] = updateQuery(2 * i + 1, k, u, l, mid)
                          + segTree[2 * i + 2];
    }
    return segTree[i] = segTree[2 * i + 1]
                      + updateQuery(2 * i + 2, k, u, mid + 1, r);
}

// O(log N)
ll rangeQuery(int i, int currL, int currR, int queryL, int queryR) {
    if(queryL <= currL && queryR >= currR)
        return segTree[i];
    else if(currR < queryL || currL > queryR)
        return 0;
    int mid = currL + (currR - currL) / 2;
    return rangeQuery(2 * i + 1, currL, mid, queryL, queryR) +
           rangeQuery(2 * i + 2, mid + 1, currR, queryL, queryR);
}

// O((N) + (Q * log N))
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    vector<ll> queries;
    segTree.resize(4 * n);
    for(int i = 0; i < n; i++) {
        ll data;
        cin >> data;
        nums.push_back(data);
    }
    buildSegTree(0, 0, n - 1);
    for(int i = 0; i < q; i++) {
        int mode, l, r, k;
        ll u;
        cin >> mode;
        if(mode == 1) {
            cin >> k >> u;
            updateQuery(0, k - 1, u, 0, n - 1);
        } else {
            cin >> l >> r;
            queries.push_back(rangeQuery(0, 0, n - 1, l - 1, r - 1));
        }
    }
    for(auto& i : queries) cout << i << '\n';
    return 0;
}