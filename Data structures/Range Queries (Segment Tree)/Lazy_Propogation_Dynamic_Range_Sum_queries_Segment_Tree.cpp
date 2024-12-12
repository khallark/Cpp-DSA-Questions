#include <iostream>
#include <vector>
#define ll long long
using namespace std;
int n, q;
vector<ll> nums;
vector<ll> queries;
vector<ll> segmTree;
vector<ll> lazyTree;

// O(2 * n)
ll buildSegTree(int i, int l, int r) {
    if(l == r) return segmTree[i] = nums[l];
    int mid = l + (r - l) / 2;
    return segmTree[i] = buildSegTree(2 * i + 1, l, mid)
                      + buildSegTree(2 * i + 2, mid + 1, r);
}

// O(log N)
ll updateRangeQuery(int i, int currL, int currR, int queryL, int queryR, int change) {
    if (lazyTree[i] != 0) { // Propogate the change to children
        segmTree[i] += (currR - currL + 1) * lazyTree[i];
        if (currL < currR) { // Check wether the node has further children or not
            lazyTree[2 * i + 1] += lazyTree[i];
            lazyTree[2 * i + 2] += lazyTree[i];
        }
        lazyTree[i] = 0;
    }


    if(currR < queryL || currL > queryR) {
        return segmTree[i];
    }
    if(queryL <= currL && queryR >= currR) {
        segmTree[i] += (currR - currL + 1) * change;
        if (currL < currR) { // Check wether the node has further children or not
            lazyTree[2 * i + 1] += change;
            lazyTree[2 * i + 2] += change;
        }
        return segmTree[i];
    }


    int mid = currL + (currR - currL) / 2;
    return segmTree[i] = updateRangeQuery(2 * i + 1, currL, mid, queryL, queryR, change) +
                         updateRangeQuery(2 * i + 2, mid + 1, currR, queryL, queryR, change);
}

// O(log N)
ll rangeQuery(int i, int currL, int currR, int queryL, int queryR) {
    if (lazyTree[i] != 0) { // Propogate the change to children
        segmTree[i] += (currR - currL + 1) * lazyTree[i];
        if (currL < currR) { // Check wether the node has further children or not
            lazyTree[2 * i + 1] += lazyTree[i];
            lazyTree[2 * i + 2] += lazyTree[i];
        }
        lazyTree[i] = 0;
    }
    

    if(currR < queryL || currL > queryR) {
        return 0;
    }
    if(queryL <= currL && queryR >= currR) {
        return segmTree[i];
    }


    int mid = currL + (currR - currL) / 2;
    return rangeQuery(2 * i + 1, currL, mid, queryL, queryR) +
           rangeQuery(2 * i + 2, mid + 1, currR, queryL, queryR);
}

// O((N) + (Q * log N))
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    segmTree.resize(4 * n, 0);
    lazyTree.resize(4 * n, 0);
    for(int i = 0; i < n; i++) {
        ll data;
        cin >> data;
        nums.push_back(data);
    }
    buildSegTree(0, 0, n - 1);
    for(int i = 0; i < q; i++) {
        int mode;
        int l, r;
        int u;
        cin >> mode;
        if(mode == 1) {
            cin >> l >> r >> u;
            updateRangeQuery(0, 0, n - 1, l - 1, r - 1, u);
        } else {
            cin >> l >> r;
            queries.push_back(rangeQuery(0, 0, n - 1, l - 1, r - 1));
        }
    }
    for(auto& i : queries) cout << i << '\n';
    return 0;
}

/*
INTPUT :
8 6
3 2 4 5 1 1 5 3
2 2 4
2 3 6
1 3 5 2
2 4 7
1 4 7 -1
2 1 8

OUTPUT :
11
11
16
26
*/

/*
INTPUT :
11 8
2 4 1 5 3 7 6 3 5 1 9
2 2 5
2 6 8
1 3 7 -3
2 5 11
1 5 9 5
1 1 5 3
2 5 10
2 1 6

OUTPUT :
13
16
25
44
35
*/