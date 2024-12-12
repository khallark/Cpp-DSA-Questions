#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int n, q;
vector<int> nums;
vector<int> segTree;

// O(2 * n)
int buildSegTree(int i, int l, int r) {
    if(l == r) return segTree[i] = nums[l];
    int mid = l + (r - l) / 2;
    return segTree[i] = min(buildSegTree(2 * i + 1, l, mid),
                        buildSegTree(2 * i + 2, mid + 1, r));
}

// O(log N)
int rangeQuery(int i, int currL, int currR, int queryL, int queryR) {
    if(queryL <= currL && queryR >= currR)
        return segTree[i];
    else if(currR < queryL || currL > queryR)
        return INT_MAX;
    int mid = currL + (currR - currL) / 2;
    return min(rangeQuery(2 * i + 1, currL, mid, queryL, queryR),
           rangeQuery(2 * i + 2, mid + 1, currR, queryL, queryR));
}


// O((N) + (Q * log N))
int main() {
    cin >> n >> q;
    nums.resize(n);
    vector<int> queries(q);
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