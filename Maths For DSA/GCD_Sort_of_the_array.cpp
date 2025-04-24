// https://leetcode.com/problems/gcd-sort-of-an-array

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

class DisjSet {
public:
    vector<int> parent;
    DisjSet(int n) {
        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    int findParent(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }
    void unionFind(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu != pv) parent[pu] = pv;
    }
};
vector<int> spf;

vector<int> primeFactors(int num) {
    vector<int> ans;
    while(num > 1) {
        ans.push_back(spf[num]);
        num /= spf[num];
    }
    return ans;
}

bool gcdSort(vector<int>& nums) {
    int maxi = *max_element(nums.begin(), nums.end());
    spf.resize(maxi + 1);

    // Seive
    for(int i = 0; i <= maxi; i++) spf[i] = i;
    for(int i = 2; i * i <= maxi; i++) {
        if(spf[i] == i) {
            for(int j = i * i; j <= maxi; j += i) {
                if(spf[j] == j) spf[j] = i;
            }
        }
    }

    DisjSet s(maxi + 1);
    for(auto i : nums) {
        vector<int> PFs = primeFactors(i);
        for(auto j : PFs) {
            s.unionFind(i, j);
        }
    }

    vector<int> sortedNums = nums;
    sort(sortedNums.begin(), sortedNums.end());
    for(int i = 0; i < nums.size(); i++) {
        if(s.findParent(nums[i]) != s.findParent(sortedNums[i])) {
            return false;
        }
    }

    return true;
}

int main() {
    vector<int> nums = {10,5,9,3,15};
    cout << gcdSort(nums);
    return 0;
}