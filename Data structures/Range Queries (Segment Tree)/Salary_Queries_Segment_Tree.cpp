#include <iostream>
#include <vector>
#include <climits>
#define pii pair<int, int>
using namespace std;
int n, q;
vector<int> salary;
vector<pii> segTree;
vector<int> queries;

// O(N)
pii buildSegTree(int i, int l, int r) {
    if(l == r) {
        return segTree[i] = {salary[l], salary[l]};
    }
    int mid = l + (r - l) / 2;
    pii left = buildSegTree(2 * i + 1, l, mid);
    pii right = buildSegTree(2 * i + 2, mid + 1, r);
    return segTree[i] = {min(left.first, right.first), max(left.second, right.second)};
}

// O(N)
pii updateQuery(int i, int l, int r, int k, int x) {
    if(l == r) {
        return segTree[i] = {x, x};
    }
    int mid = l + (r - l) / 2;
    pii left, right;
    if(k <= mid) {
        left = updateQuery(2 * i + 1, l, mid, k, x);
        right = segTree[2 * i + 2];
    } else {
        left = segTree[2 * i + 1];
        right = updateQuery(2 * i + 2, mid + 1, r, k, x);
    }
    return segTree[i] = {
        min(left.first, right.first),
        max(left.second, right.second)
    };
}

// O(log N) -> O(N)
int countQuery(int i, int l, int r, int queryA, int queryB) {
    int currA = segTree[i].first;
    int currB = segTree[i].second;
    if(queryA <= currA && queryB >= currB) {
        return r - l + 1;
    } else if(currB < queryA || currA > queryB) {
        return 0;
    }
    int mid = l + (r - l) / 2;
    return countQuery(2 * i + 1, l, mid, queryA, queryB) +
           countQuery(2 * i + 2, mid + 1, r, queryA, queryB);
}

// O(q * log N) -> O(q * N)
int main() {
    cin >> n >> q;
    salary.resize(n);
    segTree.resize(4 * n, {INT_MAX, INT_MIN});
    for(auto& i : salary) cin >> i;
    buildSegTree(0, 0, n - 1);
    for(int i = 0; i < q; i++) {
        char mode;
        int k, x;
        int a, b;
        cin >> mode;
        if(mode == '!') {
            cin >> k >> x;
            updateQuery(0, 0, n - 1, k - 1, x);
        } else {
            cin >> a >> b;
            queries.push_back(countQuery(0, 0, n - 1, a, b));
        }
    }
    for(auto i : queries) cout << i << endl;
    return 0;
}