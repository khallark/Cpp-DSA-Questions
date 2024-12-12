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

class info {
public:
    int Required_Opened_Brackets, Required_Closed_Brackets, Total_Full_Brackets_Pairs;
    info() {
        Required_Opened_Brackets = 0;
        Required_Closed_Brackets = 0;
        Total_Full_Brackets_Pairs = 0;
    }
    info(int v1, int v2, int v3) {
        Required_Opened_Brackets = v1;
        Required_Closed_Brackets = v2;
        Total_Full_Brackets_Pairs = v3;
    }
};

vector<info> segTree;
string s;
int n;
int m;

info buildTree(int index, int l, int r) {
    if(l == r) {
        return segTree[index] = info(s[l] == '(', s[l] == ')', 0);
    }

    int mid = l + (r - l) / 2;
    info left = buildTree(2 * index + 1, l, mid);
    info right = buildTree(2 * index + 2, mid + 1, r);
    int matched = min(left.Required_Opened_Brackets, right.Required_Closed_Brackets);

    return segTree[index] = info(
        left.Required_Opened_Brackets + right.Required_Opened_Brackets - matched,
        left.Required_Closed_Brackets + right.Required_Closed_Brackets - matched,
        left.Total_Full_Brackets_Pairs + right.Total_Full_Brackets_Pairs + matched
    );
}

info query(int index, int ql, int qr, int cl, int cr) {
    if(cr < ql || cl > qr) {
        return info();
    }
    
    else if(cl >= ql && cr <= qr) {
        return segTree[index];
    }

    int mid = cl + (cr - cl) / 2;
    info left = query(2 * index + 1, ql, qr, cl, mid);
    info right = query(2 * index + 2, ql, qr, mid + 1, cr);
    int matched = min(left.Required_Opened_Brackets, right.Required_Closed_Brackets);

    return info(
        left.Required_Opened_Brackets + right.Required_Opened_Brackets - matched,
        left.Required_Closed_Brackets + right.Required_Closed_Brackets - matched,
        left.Total_Full_Brackets_Pairs + right.Total_Full_Brackets_Pairs + matched
    );
}

int main() {
    cin >> s >> m;
    n = s.length();
    segTree.assign(4 * n, info());
    buildTree(0, 0, n - 1);
    vector<int> queries(m);
    for(auto& i : queries) {
        int l, r;
        cin >> l >> r;
        i = query(0, l - 1, r - 1, 0, n - 1).Total_Full_Brackets_Pairs * 2;
    }
    for(auto i : queries) cout << i << endl;
    return 0;
}

/*
())(())(())(
7
1 1
2 3
1 2
1 12
8 12
5 11
2 10

*/