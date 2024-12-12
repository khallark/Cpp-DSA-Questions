/*************************************************
 *                                               *
 *   Inversion count :                           *
 *   Number of pair of {A[i], A[j]}, such that   *  
 *   -> i < j                                    *
 *   -> A[i] > A[j]                              *
 *                                               *
 *************************************************/

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

vector<int> segTree;
vector<int> A;
vector<bool> range;
int n, maxi = 0;

int buildTree(int i, int l, int r) {
    if(l == r) return segTree[i] = range[l];
    int mid = l + (r - l) / 2;
    return segTree[i] = buildTree(2 * i + 1, l, mid) + buildTree(2 * i + 2, mid + 1, r);
}

int updateQuery(int i, int point, int l, int r) {
    if(l == r) {
        return segTree[i] = 0;
    }
    int mid = l + (r - l) / 2;
    if(point <= mid) {
        segTree[i] = updateQuery(2 * i + 1, point, l, mid) + segTree[2 * i + 2];
    } else {
        segTree[i] = segTree[2 * i + 1] + updateQuery(2 * i + 2, point, mid + 1, r);
    }
    return segTree[i];
}

int sumQuery(int i, int ql, int qr, int cl, int cr) {
    if(cr < ql || cl > qr) return 0;
    else if(cl >= ql && cr <= qr) return segTree[i];
    int mid = cl + (cr - cl) / 2;
    return sumQuery(2 * i + 1, ql, qr, cl, mid) + sumQuery(2 * i + 2, ql, qr, mid + 1, cr);
}

int main() {
    cin >> n;
    A.assign(n, 0);
    int mini = INT_MAX;
    for(auto& i : A) {
        cin >> i;
        mini = min(mini, i);
        maxi = max(maxi, i);
    }
    range.assign(maxi, false);
    segTree.assign(4 * maxi, 0);
    for(auto i : A) range[i - 1] = true;
    buildTree(0, 0, maxi - 1);
    int count = 0;
    REP(i, 0, n) {
        updateQuery(0, A[i] - 1, 0, n - 1);
        count += sumQuery(0, mini - 1, max(0, A[i] - 2), 0, maxi - 1);
    }
    cout << count << endl;
    return 0;
}