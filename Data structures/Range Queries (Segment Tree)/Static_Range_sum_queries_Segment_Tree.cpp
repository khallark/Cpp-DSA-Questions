#include <iostream>
#include <vector>
using namespace std;
int n, q;
vector<long long> nums;
vector<long long> segTree;

// O(2 * n)
long long buildSegTree(int i, int l, int r) {
    if(l == r) return segTree[i] = nums[l];
    int mid = l + (r - l) / 2;
    return segTree[i] = buildSegTree(2 * i + 1, l, mid)
                      + buildSegTree(2 * i + 2, mid + 1, r);
}

// O(log N)
long long rangeQuery(int i, int currL, int currR, int queryL, int queryR) {
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
    cin >> n >> q;
    nums.resize(n);
    vector<long long> queries(q);
    segTree.resize(4 * n);
    for(auto& i : nums) cin >> i;
    buildSegTree(0, 0, n - 1);
    for(auto& i : queries) {
        int l, r;
        cin >> l >> r;
        i = rangeQuery(0, 0, n - 1, l - 1, r - 1);
    }
    for(auto i : queries) cout << i << endl;
    return 0;
}