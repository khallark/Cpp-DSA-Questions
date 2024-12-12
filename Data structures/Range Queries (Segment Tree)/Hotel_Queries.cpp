#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, q;
vector<int> hotels;
vector<int> segTree;
vector<int> queries;

// O(log N)
int buildSegTree(int i, int l, int r) {
    if(l == r) return segTree[i] = hotels[l];
    int mid = l + (r - l) / 2;
    return segTree[i] = max(buildSegTree(2 * i + 1, l, mid), buildSegTree(2 * i + 2, mid + 1, r));
}

// O(log N)
void searchQuery(int i, int l, int r, int query, int& index) {
    if(l == r) {
        if(segTree[i] >= query && index == -1) index = l;
        return;
    }
    int mid = l + (r - l) / 2;
    if(segTree[i] < query) return;
    searchQuery(2 * i + 1, l, mid, query, index);
    if(index == -1) searchQuery(2 * i + 2, mid + 1, r, query, index);
}

// O(log N)
int updateQuery(int i, int k, int u, int l, int r) {
    if(l == r) {
        if(l == k) return segTree[i] += u;
        return segTree[i];
    }
    int mid = l + (r - l) / 2;
    if(k <= mid) {
        return segTree[i] = max(updateQuery(2 * i + 1, k, u, l, mid),
                          segTree[2 * i + 2]);
    }
    return segTree[i] = max(segTree[2 * i + 1],
                      updateQuery(2 * i + 2, k, u, mid + 1, r));
}

int main() {
    cin >> n >> q;
    hotels.resize(n);
    segTree.resize(4 * n);
    queries.resize(q);
    for(auto& i : hotels) {
        cin >> i;
    }
    buildSegTree(0, 0, n - 1);
    for(auto& i : queries) {
        int query;
        cin >> query;
        int index = -1;
        searchQuery(0, 0, n - 1, query, index);
        i = index + 1;
        if(index != -1) updateQuery(0, index, -query, 0, n - 1);
    }
    for(auto i : queries) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}