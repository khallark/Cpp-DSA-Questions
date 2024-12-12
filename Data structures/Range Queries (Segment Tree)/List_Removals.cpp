#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> segTree;
vector<int> arr;

int buildSegTree(int i, int l, int r) {
    if(l == r) {
        return segTree[i] = 1;
    }
    int mid = l + (r - l) / 2;
    return segTree[i] = buildSegTree(2 * i + 1, l, mid) + buildSegTree(2 * i + 2, mid + 1, r);
}

int updateQuery(int i, int l, int r, int index) {
    if(l == r) {
        return segTree[i] = 0;
    }
    int mid = l + (r - l) / 2;
    if(index <= mid) {
        return segTree[i] = updateQuery(2 * i + 1, l, mid, index) + segTree[2 * i + 2];
    } else {
        return segTree[i] = segTree[2 * i + 1] + updateQuery(2 * i + 2, mid + 1, r, index);    
    }
}

int getQuery(int i, int l, int r, int index) {
    if(l == r) {
        return l;
    }
    int mid = l + (r - l) / 2;
    if(index < segTree[2 * i + 1]) {
        return getQuery(2 * i + 1, l, mid, index);
    } else {
        return getQuery(2 * i + 2, mid + 1, r, index - segTree[2 * i + 1]);
    }
}

int main() {
    cin >> n;
    arr.resize(n);
    segTree.resize(4 * n);
    for(auto& i : arr) cin >> i;
    vector<int> ans(n);
    buildSegTree(0, 0, n - 1);
    for(auto& i : ans) {
        int index;
        cin >> index;
        int actualIndex = getQuery(0, 0, n - 1, index - 1);
        i = arr[actualIndex];
        updateQuery(0, 0, n - 1, actualIndex);
    }
    for(auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}